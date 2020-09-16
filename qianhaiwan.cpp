#include "qianhaiwan.h"
#include "ui_qianhaiwan.h"


qianhaiWan::qianhaiWan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qianhaiWan)
{
    ui->setupUi(this);
    //配置场景
    //设置标题
    setWindowTitle("前海湾");
    //设置固定大小
    setFixedSize(480, 360);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));

    //设置为模态
    this->setWindowModality(Qt::ApplicationModal);

    //返回主菜单
    connect(ui->backMainBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->qianhaiwanBack();
                });
    });
    //开始购票
    connect(ui->startBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->qianhaiwanTic();
                });
    });
}

qianhaiWan::~qianhaiWan()
{
    delete ui;
}
