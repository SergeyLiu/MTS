#ifndef BAOANCENTER_H
#define BAOANCENTER_H

#include <QWidget>
#include "startchoose.h"
#include <QPushButton>
#include <QTimer>

namespace Ui {
class baoanCenter;
}

class baoanCenter : public QWidget
{
    Q_OBJECT

public:
    explicit baoanCenter(QWidget *parent = nullptr);
    ~baoanCenter();
    //创建开始购票窗口指针
    startChoose * startCho;

signals:
    //返回主菜单信号
    void baoanBack();
    //开始购票信号
    void baoanTic();

private:
    Ui::baoanCenter *ui;
};

#endif // BAOANCENTER_H
