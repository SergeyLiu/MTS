#ifndef SYSSTRU_H
#define SYSSTRU_H

#include <QWidget>
#include "mainscene.h"
#include <QIcon>
#include <QPushButton>
#include <QTimer>
#include <QLabel>


namespace Ui {
class sysStru;
}

class sysStru : public QWidget
{
    Q_OBJECT

public:
    explicit sysStru(QWidget *parent = nullptr);
    ~sysStru();

    //创建主菜单指针
    mainScene * MScene;

private:
    Ui::sysStru *ui;
};

#endif // SYSSTRU_H
