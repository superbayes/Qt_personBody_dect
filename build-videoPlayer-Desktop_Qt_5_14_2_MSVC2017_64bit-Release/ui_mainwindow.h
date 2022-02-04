/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
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
    QLabel *lab_cam;
    QPushButton *pb_open;
    QPushButton *pb_close;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(985, 824);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lab_cam = new QLabel(centralwidget);
        lab_cam->setObjectName(QString::fromUtf8("lab_cam"));
        lab_cam->setGeometry(QRect(10, 10, 960, 720));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lab_cam->sizePolicy().hasHeightForWidth());
        lab_cam->setSizePolicy(sizePolicy);
        lab_cam->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pb_open = new QPushButton(centralwidget);
        pb_open->setObjectName(QString::fromUtf8("pb_open"));
        pb_open->setGeometry(QRect(10, 740, 121, 41));
        pb_close = new QPushButton(centralwidget);
        pb_close->setObjectName(QString::fromUtf8("pb_close"));
        pb_close->setGeometry(QRect(180, 740, 121, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 985, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lab_cam->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pb_open->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\350\247\206\351\242\221", nullptr));
        pb_close->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\350\247\206\351\242\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
