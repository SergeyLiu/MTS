#include "shenzhennorth.h"
#include "ui_shenzhennorth.h"


shenzhenNorth::shenzhenNorth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shenzhenNorth)
{
    ui->setupUi(this);
    //配置场景
    //设置标题
    setWindowTitle("深圳北");
    //设置固定大小
    setFixedSize(480, 360);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));

    //设置为模态
    this->setWindowModality(Qt::ApplicationModal);

    //返回主菜单
    connect(ui->backMainBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->shenzhennorthBack();
                });
    });
    //开始购票
    connect(ui->startBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->shenzhennorthTic();
                });
    });
}

shenzhenNorth::~shenzhenNorth()
{
    delete ui;
}
