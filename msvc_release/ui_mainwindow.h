/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *onreset;
    QPushButton *pushButton_set_time;
    QLineEdit *lineEdit_time;
    QLabel *label;
    QPushButton *pushButton_pause;
    QLabel *label_goal;
    QLineEdit *lineEdit_chioce;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_num;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(899, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        onreset = new QPushButton(centralwidget);
        onreset->setObjectName("onreset");
        onreset->setGeometry(QRect(750, 110, 71, 21));
        pushButton_set_time = new QPushButton(centralwidget);
        pushButton_set_time->setObjectName("pushButton_set_time");
        pushButton_set_time->setGeometry(QRect(750, 200, 71, 24));
        lineEdit_time = new QLineEdit(centralwidget);
        lineEdit_time->setObjectName("lineEdit_time");
        lineEdit_time->setGeometry(QRect(750, 160, 71, 21));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(720, 140, 131, 21));
        pushButton_pause = new QPushButton(centralwidget);
        pushButton_pause->setObjectName("pushButton_pause");
        pushButton_pause->setGeometry(QRect(750, 70, 71, 24));
        label_goal = new QLabel(centralwidget);
        label_goal->setObjectName("label_goal");
        label_goal->setGeometry(QRect(750, 30, 81, 20));
        lineEdit_chioce = new QLineEdit(centralwidget);
        lineEdit_chioce->setObjectName("lineEdit_chioce");
        lineEdit_chioce->setGeometry(QRect(750, 250, 71, 23));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(750, 290, 71, 24));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(743, 230, 91, 21));
        label_num = new QLabel(centralwidget);
        label_num->setObjectName("label_num");
        label_num->setGeometry(QRect(350, 0, 71, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 899, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        onreset->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256\346\234\254\345\261\200", nullptr));
        pushButton_set_time->setText(QCoreApplication::translate("MainWindow", "\345\272\224\347\224\250", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\351\200\237\345\272\246 (1~10),\351\273\230\350\256\2445", nullptr));
        pushButton_pause->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234/\345\274\200\345\247\213", nullptr));
        label_goal->setText(QCoreApplication::translate("MainWindow", "\346\234\254\345\261\200\345\276\227\345\210\206\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\205\263\345\215\241", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\205\263\345\215\241\351\200\211\346\213\251\357\274\2101~5", nullptr));
        label_num->setText(QCoreApplication::translate("MainWindow", "\347\254\254\344\270\200\345\205\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
