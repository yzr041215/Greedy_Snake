#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"Others/Common.h"
#include"Snake/snake.h"
#include<Qpainter>
#include <QMainWindow>
#include<ctime>
#include<QMessageBox>
#include<Windows.h>
#define Width 700
#define Height 400


#include<windows.h>
#include<QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool make_pause=0;
    int chioce=1;//地图选择
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent * ev);

private slots:

    void on_onreset_clicked();

    void on_pushButton_set_time_clicked();

    void on_pushButton_pause_clicked();

    void on_pushButton_clicked();

private:
    //函数
    bool snake_move();
    QRect make_food();
    void show_background(MainWindow*pw);//显示背景
    void show_my_map(MainWindow*pw);//显示墙体
    //变量
    bool was_eated=1;

    My_map *my_map;

    Snake *snake;
    int id1=startTimer(20);
    int id2=startTimer(200);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
