#ifndef QIANWAN_H
#define QIANWAN_H

#include <QWidget>
#include "startchoose.h"
#include <QPushButton>
#include <QTimer>

namespace Ui {
class qianWan;
}

class qianWan : public QWidget
{
    Q_OBJECT

public:
    explicit qianWan(QWidget *parent = nullptr);
    ~qianWan();
    //创建开始购票窗口指针
    startChoose * startCho;

signals:
    //返回主菜单信号
    void qianwanBack();
    //开始购票信号
    void qianwanTic();

private:
    Ui::qianWan *ui;
};

#endif // QIANWAN_H
