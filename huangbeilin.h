#ifndef HUANGBEILIN_H
#define HUANGBEILIN_H

#include <QWidget>
#include "startchoose.h"
#include <QPushButton>
#include <QTimer>

namespace Ui {
class huangbeiLin;
}

class huangbeiLin : public QWidget
{
    Q_OBJECT

public:
    explicit huangbeiLin(QWidget *parent = nullptr);
    ~huangbeiLin();
    //创建开始购票窗口指针
    startChoose * startCho;

signals:
    //返回主菜单信号
    void huangbeilinBack();
    //开始购票信号
    void huangbeilinTic();

private:
    Ui::huangbeiLin *ui;
};

#endif // HUANGBEILIN_H
