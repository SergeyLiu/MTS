#include "qianwan.h"
#include "ui_qianwan.h"


qianWan::qianWan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qianWan)
{
    ui->setupUi(this);
    //配置场景
    //设置标题
    setWindowTitle("前湾");
    //设置固定大小
    setFixedSize(480, 360);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));

    //设置为模态
    this->setWindowModality(Qt::ApplicationModal);

    //返回主菜单
    connect(ui->backMainBtb, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->qianwanBack();
                });
    });
    //开始购票
    connect(ui->startBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->qianwanTic();
                });
    });
}

qianWan::~qianWan()
{
    delete ui;
}
