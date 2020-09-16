#ifndef XILI_H
#define XILI_H

#include <QWidget>
#include "startchoose.h"
#include <QPushButton>
#include <QTimer>

namespace Ui {
class xiLi;
}

class xiLi : public QWidget
{
    Q_OBJECT

public:
    explicit xiLi(QWidget *parent = nullptr);
    ~xiLi();
    //创建开始购票窗口指针
    startChoose * startCho;

signals:
    //返回主菜单信号
    void xiliBack();
    //开始购票信号
    void xiliTic();

private:
    Ui::xiLi *ui;
};

#endif // XILI_H
