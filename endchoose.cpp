#include "endchoose.h"
#include "ui_endchoose.h"


extern int startFlag;

//定义选择终点站代号
int endFlag=0;

endChoose::endChoose(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::endChoose)
{
    ui->setupUi(this);

    //配置界面
    //设置标题
    setWindowTitle("选择终点站");
    //设置固定大小
    setFixedSize(960, 720);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));
    //设置提示信息
    ui->searchLb1->setStyleSheet( "font:bold 20px;" );

    //设置返回按钮
    QPushButton * endTicBtn = new QPushButton(this);
    endTicBtn->resize(200, 80);
    endTicBtn->setText("返回主菜单");
    endTicBtn->move(0, this->height()-endTicBtn->height());
    //点击返回后延时发送返回信号
    connect(endTicBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->endChooseBack();
                });
    });

    ticketing = new Tic;
    connect(ticketing, &Tic::ticBack, this, [=](){
        ticketing->hide();
        QTimer::singleShot(50, this, [=](){
            emit this->endChooseBack();
        });
    });

    //监听购票窗口返回选择始发站信号
    connect(ticketing, &Tic::backChoose, this, [=](){
        QTimer::singleShot(50, this, [=](){
            emit this->backChoose();
        });
    });

    //设置站点：1-8号，赤湾、前湾、前海湾、宝安中心、西丽、大学城、深圳北、黄贝岭
    //1、赤湾
    setBtnStyle(ui->chiWan);
    connect(ui->chiWan, &QPushButton::clicked, this, [=](){
        endFlag = 1;
        int check = checkFlag(startFlag, endFlag);
        if(check){
            ticketing->stationCount = setStation(ticketing->startStation, ticketing->endStation, ticketing->ticNum, startFlag, endFlag);
            QTimer::singleShot(50, this, [=](){
                changeWidget(this, ticketing);
            });
        }
        ticketing->ui->TicSpinBox->setValue(1);
    });
    //2、前湾
    setBtnStyle(ui->qianWan);
    connect(ui->qianWan, &QPushButton::clicked, this, [=](){
        endFlag = 2;
        int check = checkFlag(startFlag, endFlag);
        if(check){
            ticketing->stationCount = setStation(ticketing->startStation, ticketing->endStation, ticketing->ticNum, startFlag, endFlag);
            QTimer::singleShot(50, this, [=](){
                changeWidget(this, ticketing);
            });
        }
        ticketing->ui->TicSpinBox->setValue(1);
    });
    //3、前海湾
    setBtnStyle(ui->qianHaiWan);
    connect(ui->qianHaiWan, &QPushButton::clicked, this, [=](){
        endFlag = 3;
        int check = checkFlag(startFlag, endFlag);
        if(check){
            ticketing->stationCount = setStation(ticketing->startStation, ticketing->endStation, ticketing->ticNum, startFlag, endFlag);
            QTimer::singleShot(50, this, [=](){
                changeWidget(this, ticketing);
            });
        }
        ticketing->ui->TicSpinBox->setValue(1);
    });
    //4、宝安中心
    setBtnStyle(ui->baoAnCenter);
    connect(ui->baoAnCenter, &QPushButton::clicked, this, [=](){
        endFlag = 4;
        int check = checkFlag(startFlag, endFlag);
        if(check){
            ticketing->stationCount = setStation(ticketing->startStation, ticketing->endStation, ticketing->ticNum, startFlag, endFlag);
            QTimer::singleShot(50, this, [=](){
                changeWidget(this, ticketing);
            });
        }
        ticketing->ui->TicSpinBox->setValue(1);
    });
    //5、西丽
    setBtnStyle(ui->xiLi);
    connect(ui->xiLi, &QPushButton::clicked, this, [=](){
        endFlag = 5;
        int check = checkFlag(startFlag, endFlag);
        if(check){
            ticketing->stationCount = setStation(ticketing->startStation, ticketing->endStation, ticketing->ticNum, startFlag, endFlag);
            QTimer::singleShot(50, this, [=](){
                changeWidget(this, ticketing);
            });
        }
        ticketing->ui->TicSpinBox->setValue(1);
    });
    //6、大学城
    setBtnStyle(ui->univerCity);
    connect(ui->univerCity, &QPushButton::clicked, this, [=](){
        endFlag = 6;
        int check = checkFlag(startFlag, endFlag);
        if(check){
            ticketing->stationCount = setStation(ticketing->startStation, ticketing->endStation, ticketing->ticNum, startFlag, endFlag);
            QTimer::singleShot(50, this, [=](){
                changeWidget(this, ticketing);
            });
        }
        ticketing->ui->TicSpinBox->setValue(1);
    });
    //7、深圳北
    setBtnStyle(ui->shenzhenNorth);
    connect(ui->shenzhenNorth, &QPushButton::clicked, this, [=](){
        endFlag = 7;
        int check = checkFlag(startFlag, endFlag);
        if(check){
            ticketing->stationCount = setStation(ticketing->startStation, ticketing->endStation, ticketing->ticNum, startFlag, endFlag);
            QTimer::singleShot(50, this, [=](){
                changeWidget(this, ticketing);
            });
        }
        ticketing->ui->TicSpinBox->setValue(1);
    });
    //8、黄贝岭
    setBtnStyle(ui->huangBeiLing);
    connect(ui->huangBeiLing, &QPushButton::clicked, this, [=](){
        endFlag = 8;
        int check = checkFlag(startFlag, endFlag);
        if(check){
            ticketing->stationCount = setStation(ticketing->startStation, ticketing->endStation, ticketing->ticNum, startFlag, endFlag);
            QTimer::singleShot(50, this, [=](){
                changeWidget(this, ticketing);
            });
        }
        ticketing->ui->TicSpinBox->setValue(1);
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

endChoose::~endChoose()
{
    delete ui;
}
