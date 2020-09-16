#ifndef QIANHAIWAN_H
#define QIANHAIWAN_H

#include <QWidget>
#include "startchoose.h"
#include <QPushButton>
#include <QTimer>

namespace Ui {
class qianhaiWan;
}

class qianhaiWan : public QWidget
{
    Q_OBJECT

public:
    explicit qianhaiWan(QWidget *parent = nullptr);
    ~qianhaiWan();
    //创建开始购票窗口指针
    startChoose * startCho;

signals:
    //返回主菜单信号
    void qianhaiwanBack();
    //开始购票信号
    void qianhaiwanTic();

private:
    Ui::qianhaiWan *ui;
};

#endif // QIANHAIWAN_H
