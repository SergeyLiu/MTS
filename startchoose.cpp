#include "startchoose.h"
#include "ui_startchoose.h"


//定义选择站代号
int startFlag=0;

startChoose::startChoose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::startChoose)
{
    ui->setupUi(this);

    //配置场景
    //设置标题
    setWindowTitle("选择始发站");
    //设置固定大小
    setFixedSize(960, 720);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));

    //设置返回按钮
    QPushButton * startTicBackBtn = new QPushButton;
    startTicBackBtn->setParent(this);
    //点击返回后延时发送返回信号
    connect(startTicBackBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->startChooseBack();
                });
    });
    startTicBackBtn->resize(200, 80);
    startTicBackBtn->setText("返回主菜单");
    startTicBackBtn->move(0, this->height()-startTicBackBtn->height());

    //设置提示信息
    ui->searchLb1->setStyleSheet( "font:bold 20px;" );

    //设置站点：1-8号，赤湾、前湾、前海湾、宝安中心、西丽、大学城、深圳北、黄贝岭
    endC = new endChoose;
    connect(endC, &endChoose::endChooseBack, this, [=](){
        endC->hide();
        QTimer::singleShot(50, this, [=](){
            emit this->startChooseBack();
        });
    });
    //监听返回选择始发站信号
    connect(endC, &endChoose::backChoose, this, [=](){
        this->show();
    });
    //1、赤湾
    setBtnStyle(ui->chiWan);
    connect(ui->chiWan, &QPushButton::clicked, this, [=](){
        startFlag = 1;
        QTimer::singleShot(50, this, [=](){
            this->hide();
            endC->show();
        });
    });
    //2、前湾
    setBtnStyle(ui->qianWan);
    connect(ui->qianWan, &QPushButton::clicked, this, [=](){
        startFlag = 2;
        QTimer::singleShot(50, this, [=](){
            this->hide();
            endC->show();
        });
    });
    //3、前海湾
    setBtnStyle(ui->qianHaiWan);
    connect(ui->qianHaiWan, &QPushButton::clicked, this, [=](){
        startFlag = 3;
        QTimer::singleShot(50, this, [=](){
            this->hide();
            endC->show();
        });
    });
    //4、宝安中心
    setBtnStyle(ui->baoAnCenter);
    connect(ui->baoAnCenter, &QPushButton::clicked, this, [=](){
        startFlag = 4;
        QTimer::singleShot(50, this, [=](){
            this->hide();
            endC->show();
        });
    });
    //5、西丽
    setBtnStyle(ui->xiLi);
    connect(ui->xiLi, &QPushButton::clicked, this, [=](){
        startFlag = 5;
        QTimer::singleShot(50, this, [=](){
            this->hide();
            endC->show();
        });
    });
    //6、大学城
    setBtnStyle(ui->univerCity);
    connect(ui->univerCity, &QPushButton::clicked, this, [=](){
        startFlag = 6;
        QTimer::singleShot(50, this, [=](){
            this->hide();
            endC->show();
        });
    });
    //7、深圳北
    setBtnStyle(ui->shenzhenNorth);
    connect(ui->shenzhenNorth, &QPushButton::clicked, this, [=](){
        startFlag = 7;
        QTimer::singleShot(50, this, [=](){
            this->hide();
            endC->show();
        });
    });
    //8、黄贝岭
    setBtnStyle(ui->huangBeiLing);
    connect(ui->huangBeiLing, &QPushButton::clicked, this, [=](){
        startFlag = 8;
        QTimer::singleShot(50, this, [=](){
            this->hide();
            endC->show();
        });
    });
    //设置线条样式
    setLineStyle(ui->line);
    setLineStyle(ui->line_2);
    setLineStyle(ui->line_3);
    setLineStyle(ui->line_4);
    setLineStyle(ui->line_5);
    setLineStyle(ui->line_6);
    setLineStyle(ui->line_7);
    setLineStyle(ui->line_8);
    setLineStyle(ui->line_9);
}


startChoose::~startChoose()
{
    delete ui;
}
