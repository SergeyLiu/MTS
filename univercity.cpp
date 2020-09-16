#include "univercity.h"
#include "ui_univercity.h"

univerCity::univerCity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::univerCity)
{
    ui->setupUi(this);
    //配置场景
    //设置标题
    setWindowTitle("大学城");
    //设置固定大小
    setFixedSize(480, 360);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));

    //设置为模态
    this->setWindowModality(Qt::ApplicationModal);

    //返回主菜单
    connect(ui->backMainBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->univerBack();
                });
    });
    //开始购票
    connect(ui->startBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->univerTic();
                });
    });
}

univerCity::~univerCity()
{
    delete ui;
}
