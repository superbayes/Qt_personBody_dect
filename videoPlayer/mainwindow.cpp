#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QPainter>
#include <QThread>
#include <QTimer>
#include <omp.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pTimer = new QTimer;
    m_pTimer->setInterval(100);  //定时30毫秒读取一帧数据
    dancingDetor = new NanoDet_Dancing(
                "./model/dancing_20220203-opt-fp16.param",
                "./model/dancing_20220203-opt-fp16.bin", TRUE);
    //moveNetDetor = new NanoDet_MoveNet("./model/lightning", TRUE);

    connect(m_pTimer, &QTimer::timeout, this,[&](){
        if (!cap.isOpened())
        {
            if(m_pTimer->isActive())m_pTimer->stop();
            return;
        }

        cap >> frame;

        if (frame.empty())
        {
            if(m_pTimer->isActive())m_pTimer->stop();
            return;
        }

        //AI MODEL can insert here
        auto result = dancingDetor->detect(frame, 0.5, 0.5);
        dancingDetor->draw(frame,result);
        //

        MyUtils::Mat2QImage(frame,qimg);
        this->qimg2pixmap = QPixmap::fromImage(qimg);
        this->ui->lab_cam->setPixmap(qimg2pixmap);//显示图像
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    this->cap.release();
    delete m_pTimer;
    if(dancingDetor!=nullptr)delete dancingDetor;
    //if(moveNetDetor!=nullptr)delete  moveNetDetor;
}


void MainWindow::on_pb_open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("open image file"),
                "./", tr("Image files(*.mp4 *.avi);;All files (*.*)"));

    if(fileName.isEmpty())
    {
        QMessageBox mesg;
        mesg.warning(this,"警告","打开video失败!");
        return;
    }else
    {
        qDebug()<<fileName;
        cap.open(fileName.toStdString());
        if(!cap.isOpened())return;
        m_pTimer->start();
    }

}

void MainWindow::on_MainWindow_destroyed()
{
    this->flag_closeVideoCapture=false;
    if(m_pTimer->isActive())m_pTimer->stop();
}

void MainWindow::on_pb_close_clicked()
{
    this->flag_closeVideoCapture=false;
    if(m_pTimer->isActive())m_pTimer->stop();
}
