#ifndef TIC_H
#define TIC_H

#include <QWidget>
#include <QLabel>
#include <paytic.h>
#include <QPushButton>
#include <QTimer>
#include <QSpinBox>
#include "ui_paytic.h"
#include <QKeyEvent>
#include <QMessageBox>


namespace Ui {
class Tic;
}

class Tic : public QWidget
{
    Q_OBJECT

public:
    explicit Tic(QWidget *parent = nullptr);
    ~Tic();

    Ui::Tic *ui;

    //始发站
    QLabel * startStation = new QLabel(this);
    //终点站
    QLabel * endStation = new QLabel(this);
    //票数
    QLabel * ticNum = new QLabel(this);
    //站点数
    int stationCount;

    //定义计算票价函数，起步价2元走3站，往后每1站加1元
    int calcPrice(int stationCount)
    {
        int price;
        if(0 < stationCount&&stationCount < 4)
            price = 2;
        else
        {
            price = 2 + stationCount - 3;
        }
        return  price;
    }

    //定义票数
    int TicNum = 1;

    //声明支付窗口指针
    payTic * paytic;

    //重写ESC
    void keyPressEvent(QKeyEvent *event);



signals:
    //自定义返回主菜单信号
    void ticBack();

    //传递总价
    void sendPrice(int price);

    //返回始发站选择信号
    void backChoose();

private:

};

#endif // TIC_H
