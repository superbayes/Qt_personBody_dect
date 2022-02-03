#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myutils.h"
#include <QDebug>
#include "AI/nanodet_dancing.h"
#include "AI/nanodet_movenet.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    NanoDet_Dancing* dancingDetor=nullptr;
    //NanoDet_MoveNet* moveNetDetor=nullptr;
public:
    cv::VideoCapture cap;
    cv::Mat frame;
    QImage qimg;
    QPixmap qimg2pixmap;
    bool flag_closeVideoCapture = false;//是否关闭VideoCapture
    QTimer *m_pTimer;//定时获取video frame
private slots:
    void on_pb_open_clicked();

    void on_MainWindow_destroyed();

    void on_pb_close_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
