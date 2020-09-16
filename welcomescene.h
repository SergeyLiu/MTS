#ifndef WELCOMESCENE_H
#define WELCOMESCENE_H

#include <QWidget>
#include "sysstru.h"
#include <QPainter>
#include <QPushButton>
#include <QPixmap>
#include <QTimer>

namespace Ui {
class welcomeScene;
}

class welcomeScene : public QWidget
{
    Q_OBJECT

public:
    explicit welcomeScene(QWidget *parent = nullptr);
    ~welcomeScene();

    //重写paintEvent事件
    void paintEvent(QPaintEvent *);

    //创建系统说明场景空指针
    sysStru * sysScene;

private:
    Ui::welcomeScene *ui;
};

#endif // WELCOMESCENE_H
