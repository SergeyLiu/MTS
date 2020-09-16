#ifndef UNIVERCITY_H
#define UNIVERCITY_H

#include <QWidget>
#include "startchoose.h"
#include <QPushButton>
#include <QTimer>


namespace Ui {
class univerCity;
}

class univerCity : public QWidget
{
    Q_OBJECT

public:
    explicit univerCity(QWidget *parent = nullptr);
    ~univerCity();
    //创建开始购票窗口指针
    startChoose * startCho;

signals:
    //返回主菜单信号
    void univerBack();
    //开始购票信号
    void univerTic();

private:
    Ui::univerCity *ui;
};

#endif // UNIVERCITY_H
