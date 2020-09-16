#ifndef ENDCHOOSE_H
#define ENDCHOOSE_H

#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include "tic.h"
#include "ui_tic.h"
#include <QMessageBox>
#include <QTimer>


namespace Ui {
class endChoose;
}

class endChoose : public QWidget
{
    Q_OBJECT

public:
    explicit endChoose(QWidget *parent = nullptr);
    ~endChoose();
    //创建购票窗口指针
    Tic * ticketing;

    //设置返回按钮
    QPushButton * endTicBackBtn;

    //定义修改按钮样式函数
    void setBtnStyle(QPushButton * Btn)
    {
        Btn->setStyleSheet(
                    //正常状态样式
                      "QPushButton{"
                      "background-color:rgba(100,225,100,150);"//背景色（也可以设置图片）
                      "border-style:inset;"                  //边框样式（inset/outset）
                      "border-width:4px;"                     //边框宽度像素
                      "border-radius:10px;"                   //边框圆角半径像素
                      "border-color:rgba(255,255,255,30);"    //边框颜色
                      "font:bold 22px;"                       //字体，字体大小
                      "color:rgba(0,0,0,200);"                //字体颜色
                      "padding:6px;"                          //填衬
                      "}"
                      //鼠标按下样式
                      "QPushButton:pressed{"
                      "background-color:rgba(100,255,100,200);"
                      "border-color:rgba(255,255,255,30);"
                      "border-style:inset;"
                      "color:rgba(0,0,0,100);"
                      "}"
                      //鼠标悬停样式
                      "QPushButton:hover{"
                      "background-color:rgba(100,255,100,100);"
                      "border-color:rgba(255,255,255,200);"
                      "color:rgba(0,0,0,200);"
                      "}"
                    );
    }

    //定义修改线条样式函数
    void setLineStyle(QFrame * Line)
    {
        Line->setStyleSheet("border-top: 1px solid green; "
                            "background-color: green;");
    }

    //定义判断选择站点是否冲突函数
    int checkFlag(int startFlag, int endFlag)
    {
        if(startFlag == endFlag)
        {
            //错误输入弹出提示框
            QMessageBox::critical(this, "Error", "始发站与终点站冲突！");
            return 0;
        }
        else
        {
            return 1;
        }
    }
    //定义显示站点函数
    int setStation(QLabel * startLb, QLabel * endLb, QLabel * ticNum, int startflag, int endflag)
    {
        int Num = endflag > startflag? endflag-startflag:startflag-endflag;
        QString countNum = QString::number(Num);
        countNum = countNum + "站";
        ticNum->setText(countNum);
        startLb->resize(200, 50);
        startLb->move(180, 0);
        startLb->setStyleSheet("font:bold 30px;" );
        endLb->resize(200, 50);
        endLb->move(180, 120);
        endLb->setStyleSheet("font:bold 30px;");
        ticNum->resize(200, 50);
        ticNum->move(120, 240);
        ticNum->setStyleSheet("font:bold 30px;");

        switch (startflag) {
        case 1:
            startLb->setText("赤湾");
            break;
        case 2:
            startLb->setText("前湾");
            break;
        case 3:
            startLb->setText("前海湾");
            break;
        case 4:
            startLb->setText("宝安中心");
            break;
        case 5:
            startLb->setText("西丽");
            break;
        case 6:
            startLb->setText("大学城");
            break;
        case 7:
            startLb->setText("深圳北");
            break;
        case 8:
            startLb->setText("黄贝岭");
            break;
        default:
            startLb->setText("请选择站点");
            break;
        }
        switch (endflag) {
        case 1:
            endLb->setText("赤湾");
            break;
        case 2:
            endLb->setText("前湾");
            break;
        case 3:
            endLb->setText("前海湾");
            break;
        case 4:
            endLb->setText("宝安中心");
            break;
        case 5:
            endLb->setText("西丽");
            break;
        case 6:
            endLb->setText("大学城");
            break;
        case 7:
            endLb->setText("深圳北");
            break;
        case 8:
            endLb->setText("黄贝岭");
            break;
        default:
            endLb->setText("请选择站点");
            break;
        }
        return Num;
    }

    //定义页面交替函数
    void changeWidget(QWidget * hideWid, QWidget * showWid)
    {
        hideWid->hide();
        showWid->show();
    }

signals:
    //自定义返回主菜单信号
    void endChooseBack();

    //定义返回选择始发站信号
    void backChoose();

private:
    Ui::endChoose *ui;
};

#endif // ENDCHOOSE_H
