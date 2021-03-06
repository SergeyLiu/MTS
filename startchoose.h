#ifndef STARTCHOOSE_H
#define STARTCHOOSE_H

#include <QWidget>
#include <QPushButton>
#include "endchoose.h"
#include <QFrame>
#include <QIcon>
#include <QTimer>


namespace Ui {
class startChoose;
}

class startChoose : public QWidget
{
    Q_OBJECT

public:
    explicit startChoose(QWidget *parent = nullptr);
    ~startChoose();

    //设置返回按钮
    QPushButton * startTicBackBtn;

    //创建选择终点站指针
    endChoose * endC;

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

signals:
    //自定义返回主菜单信号
    void startChooseBack();


private:
    Ui::startChoose *ui;
};

#endif // STARTCHOOSE_H
