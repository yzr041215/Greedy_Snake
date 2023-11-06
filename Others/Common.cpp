#include"Common.h"
#include<QFile>
#include<QCoreApplication>
#include<QDebug>
void My_map::make_barry(int num){
    QString str="barriers_"+QString::number(num)+".txt";
    QFile file(str);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    if(!file.exists())qDebug()<<"文件不存在";
    int i=0,j=0;
    while(!file.atEnd()){
        QString a= file.readLine();j=0;
        for(QChar t:a){
            if(t=='1'){
                inf[i][j]=barry;
            }else if(inf[i][j]==food){
                inf[i][j]=food;
            }else inf[i][j]=empty;
            j++;
        }
        i++;
    }
    file.close();
}
void My_map::make_food(){
    if(is_eated){
        int x=0,y=0;
        do{
            x=rand()%20;y=rand()%35;
        }
        while(inf[x][y]!=empty);
        //qDebug()<<x<<Qt::endl<<y;
        inf[x][y]=food;is_eated=0;
        now_food.setX(x),now_food.setY(y);
    }

}
void My_map::reset_food(){
    inf[now_food.x()][now_food.y()]=empty;
    is_eated=1;
    make_food();
}

