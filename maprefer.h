#ifndef MAPREFER_H
#define MAPREFER_H

#include <QWidget>
#include "startchoose.h"
#include "chiwan.h"
#include "qianwan.h"
#include "qianhaiwan.h"
#include "baoancenter.h"
#include "xili.h"
#include "univercity.h"
#include "shenzhennorth.h"
#include "huangbeilin.h"
#include <QFrame>
#include <QIcon>
#include <QPushButton>
#include <QTimer>
#include <QLineEdit>
#include <QMessageBox>



namespace Ui {
class mapRefer;
}

class mapRefer : public QWidget
{
    Q_OBJECT

public:
    explicit mapRefer(QWidget *parent = nullptr);
    ~mapRefer();

    //创建开始购票窗口指针
    startChoose * startCho;

    //创建各地铁站指针
    chiWan * chiwan;
    qianWan * qianwan;
    qianhaiWan * qianhaiwan;
    baoanCenter * baoan;
    xiLi * xili;
    univerCity * univer;
    shenzhenNorth * shenzhenn;
    huangbeiLin * huangbeiling;

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
    void mapreferBack();


private:
    Ui::mapRefer *ui;
};

#endif // MAPREFER_H
