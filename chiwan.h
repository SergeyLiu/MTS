#ifndef CHIWAN_H
#define CHIWAN_H

#include <QWidget>
#include "startchoose.h"
#include <QPushButton>
#include <QTimer>

namespace Ui {
class chiWan;
}

class chiWan : public QWidget
{
    Q_OBJECT

public:
    explicit chiWan(QWidget *parent = nullptr);
    ~chiWan();

    //创建开始购票窗口指针
    startChoose * startCho;

signals:
    //返回主菜单信号
    void chiwanBack();
    //开始购票信号
    void chiwanTic();

private:
    Ui::chiWan *ui;
};

#endif // CHIWAN_H
