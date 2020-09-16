#include "chiwan.h"
#include "ui_chiwan.h"


chiWan::chiWan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chiWan)
{
    ui->setupUi(this);
    //配置界面
    //设置标题
    setWindowTitle("赤湾");
    //设置固定大小
    setFixedSize(480, 360);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));

    //设置为模态
    this->setWindowModality(Qt::ApplicationModal);
    //返回主菜单
    connect(ui->backMainBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->chiwanBack();
                });
    });
    //开始购票
    connect(ui->startBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->chiwanTic();
                });
    });
}

chiWan::~chiWan()
{
    delete ui;
}
