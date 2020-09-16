#ifndef SHENZHENNORTH_H
#define SHENZHENNORTH_H

#include <QWidget>
#include "startchoose.h"
#include <QPushButton>
#include <QTimer>

namespace Ui {
class shenzhenNorth;
}

class shenzhenNorth : public QWidget
{
    Q_OBJECT

public:
    explicit shenzhenNorth(QWidget *parent = nullptr);
    ~shenzhenNorth();
    //创建开始购票窗口指针
    startChoose * startCho;

signals:
    //返回主菜单信号
    void shenzhennorthBack();
    //开始购票信号
    void shenzhennorthTic();

private:
    Ui::shenzhenNorth *ui;
};

#endif // SHENZHENNORTH_H
