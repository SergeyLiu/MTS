#include "xili.h"
#include "ui_xili.h"


xiLi::xiLi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::xiLi)
{
    ui->setupUi(this);
    //配置场景
    //设置标题
    setWindowTitle("西丽");
    //设置固定大小
    setFixedSize(480, 360);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));

    //设置为模态
    this->setWindowModality(Qt::ApplicationModal);

    //返回主菜单
    connect(ui->backMainBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->xiliBack();
                });
    });
    //开始购票
    connect(ui->startBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->xiliTic();
                });
    });
}

xiLi::~xiLi()
{
    delete ui;
}
