#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "qffmpeg.h"
#include <QImage>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
        QFFmpeg *f;
    ~Widget();

private:
    Ui::Widget *ui;

private slots:
    void setImage(const QImage &image);
    void on_pushButton_clicked();
};

#endif // WIDGET_H
