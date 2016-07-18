#include "widget.h"
#include "ui_widget.h"
#include "rtspthread.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    /*f = new QFFmpeg(this);
    f->SetUrl("rtsp://admin:Thinkjoy2015@192.168.0.199:554/h264/ch1/main/av_stream");
    f->Init();
    connect(f,SIGNAL(GetImage(QImage)),this,SLOT(setImage(QImage)));*/
    //f->Play();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setImage(const QImage &image)
{
    QPixmap pix = QPixmap::fromImage(image);
    ui->label_2->setPixmap(pix);
}

void Widget::on_pushButton_clicked()
{
    if (ui->lineEdit->text() == 0)
    {
        QMessageBox::warning(this,"Warning","Please input address",QMessageBox::Ok);
    }
    else
    {
        QFFmpeg *f = new QFFmpeg(this);
        f->SetUrl(ui->lineEdit->text());
        if(f->Init())
        {
            connect(f,SIGNAL(GetImage(QImage)),this,SLOT(setImage(QImage)));
            RtspThread *t = new RtspThread(this);
            t->setffmpeg(f);
            t->start();
        }
        else
        {
            QMessageBox::warning(this,"Warning","Open rtsp failed",QMessageBox::Ok);
        }

    }

}
