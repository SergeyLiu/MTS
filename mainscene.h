#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include "startchoose.h"
#include "maprefer.h"
#include <QPainter>
#include <QIcon>
#include <QTimer>


namespace Ui {
class mainScene;
}

class mainScene : public QWidget
{
    Q_OBJECT

public:
    explicit mainScene(QWidget *parent = nullptr);
    ~mainScene();

    //重写paintEvent事件
    void paintEvent(QPaintEvent *);

    //创建开始购票窗口指针
    startChoose * startCho;

    //创建地图查询窗口指针
    mapRefer * mapRef;

    //创建停止购票窗口指针
    endChoose * endC;

    //定义页面交替函数
    void changeWidget(QWidget * hideWid, QWidget * showWid)
    {
        hideWid->hide();
        showWid->show();
    }

private:
    Ui::mainScene *ui;
};

#endif // MAINSCENE_H
