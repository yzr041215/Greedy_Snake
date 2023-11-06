#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    my_map=new My_map;
    my_map->make_barry(1);
    QRect rect(80,40,20,20);
    snake=new Snake(rect);
    srand(time(NULL));
    my_map->reset_food();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::timerEvent(QTimerEvent * ev){
    if(ev->timerId()==id1){//每间隔id1ms刷新页面
        update();
    }
    if(ev->timerId()==id2&&!make_pause){//判断键盘信息
        if(snake_move()){
            QMessageBox::information(this,"提示","失败,点击ok继续（可Esc退出）");
            //snake->Reset();
            //my_map->reset_food();
            on_onreset_clicked();//重置
        }
    }

}
void MainWindow::paintEvent(QPaintEvent *){
    show_background(this);

    show_my_map(this);
}
bool MainWindow::snake_move(){
    if(GetAsyncKeyState(VK_ESCAPE)){this->close();delete this;}
    snake_direction a=snake->direction;
    if(GetAsyncKeyState(VK_UP)){
        a=snake_up;
    }else if(GetAsyncKeyState(VK_DOWN)){
        a=snake_down;
    }else if(GetAsyncKeyState(VK_LEFT)){
        a=snake_left;
    }else if(GetAsyncKeyState(VK_RIGHT)){
        a=snake_right;
    }
    bool ok=0;
    snake->direction=a;
    my_map->make_barry(chioce);
    ok= snake->move(a,my_map->is_eated);
    my_map->make_food();


    for(auto t:snake->snake_inf){

        if(my_map->inf[t.top()/20-1][t.left()/20-1]==empty){
            my_map->inf[t.top()/20-1][t.left()/20-1]=body;
        }else if(my_map->inf[t.top()/20-1][t.left()/20-1]==food){
            my_map->is_eated=1;
            //qDebug()<<"吃掉了";
            my_map->inf[t.top()/20-1][t.left()/20-1]=body;
        }else{
            return 1;
        }

    }
    return ok;
}
void MainWindow::show_my_map(MainWindow*pw){
    ui->label_goal->setText("本局得分:"+QString::number(snake->snake_inf.size(),10)+"/20");
    QFont font("楷体",20);
    ui->label_num->setFont(font);
    ui->label_num->setText("第"+QString::number(chioce,10)+"/5关");
    if(snake->snake_inf.size()>=20){

        if(chioce==5){
            make_pause=1;
            QMessageBox::information(this,"恭喜全部通过","按Esc退出");
            delete this;
        }else{
            //QMessageBox::information(this,"恭喜全部通过","按Esc退出");
            chioce++;
            on_onreset_clicked();

        }
    }
    QPainter p(pw);
    QBrush brush;
    QPen pen(Qt::black, 4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    p.setBrush(brush);
    p.setPen(pen);
    for(int i=0;i<20;i++){
    for(int j=0;j<35;j++){
        switch(my_map->inf[i][j]){
        case barry:
            brush.setStyle(Qt::NoBrush);
            pen.setColor(Qt::gray);brush.setColor(Qt::gray);p.setBrush(brush);p.setPen(pen);
            p.drawRect(20+j*20,20+i*20,20,20);
            break;

        case food:
            brush.setStyle(Qt::SolidPattern);
            pen.setColor(Qt::red);brush.setColor(Qt::red);p.setBrush(brush);p.setPen(pen);
            p.drawEllipse(20+j*20,20+i*20,20,20);
            break;

        case body:
            brush.setStyle(Qt::SolidPattern);
            //qDebug()<<j<<" "<<snake->snake_inf.front().x()/35-1;
            if(i==snake->snake_inf.front().y()/20-1&&j==snake->snake_inf.front().x()/20-1){
                pen.setColor(0xf234ea);brush.setColor(0xf3a4f4);
            }else{
                pen.setColor(0x65a2d3);brush.setColor(0xf3a444);
            }p.setBrush(brush);p.setPen(pen);
            p.drawRect(20+j*20,20+i*20,20,20);
            break;

        default:
            break;
        };
    }
    }

}
void MainWindow::show_background(MainWindow*pw){
    QPainter p(pw);
    QPen pen(Qt::black, 4, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    p.setPen(pen);
    p.drawRect(20,20,Width,Height);  // 绘制矩形
}

void MainWindow::on_onreset_clicked()
{
    snake->Reset();
    snake->direction=snake_right;
    my_map->make_food();
}

void MainWindow::on_pushButton_set_time_clicked()
{
    int x=ui->lineEdit_time->text().toInt();
    killTimer(id2);
    if(x<=10&&x>=1)
    {
        id2=startTimer(1000/x);
    }
}

void MainWindow::on_pushButton_pause_clicked()
{
    if(make_pause==0)
        make_pause=1;
    else
        make_pause=0;
}


void MainWindow::on_pushButton_clicked()
{
    chioce=ui->lineEdit_chioce->text().toInt();
    on_onreset_clicked();
}

