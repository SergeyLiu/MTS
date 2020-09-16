#include "maprefer.h"
#include "ui_maprefer.h"



mapRefer::mapRefer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mapRefer)
{
    ui->setupUi(this);

    //配置界面
    //设置标题
    setWindowTitle("地图查询");
    //设置固定大小
    setFixedSize(960, 720);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));
    //设置提示信息
    ui->searchLb1->setStyleSheet( "font:bold 20px;" );
    ui->searchLb2->setStyleSheet( "font:bold 20px;" );

    //设置返回按钮
    QPushButton * mapRefBackBtn = new QPushButton;
    mapRefBackBtn->setParent(this);
    mapRefBackBtn->resize(200, 80);
    mapRefBackBtn->setText("返回主菜单");
    mapRefBackBtn->move(0, this->height()-mapRefBackBtn->height());
    //点击返回后延时发送返回信号
    connect(mapRefBackBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->mapreferBack();
                });
    });

    //设置开始购票按钮
    QPushButton * startChoBtn = new QPushButton;
    startChoBtn->setParent(this);
    startChoBtn->resize(200, 80);
    startChoBtn->setText("开始购票");
    startChoBtn->move(this->width()-startChoBtn->width(), this->height()-startChoBtn->height());



    //查询按钮实现
    connect(ui->searchBtn, &QPushButton::clicked, this, [=](){
        QString strFlag = ui->lineEdit->text();
        int floatFlag = strFlag.toInt();
        //判断输入
        if(floatFlag == 1 || floatFlag == 2 || floatFlag == 3 || floatFlag == 4 || floatFlag == 5 || floatFlag == 6 || floatFlag == 7 || floatFlag == 8){
            //正确输入
            //赤湾
            if(floatFlag == 1){
               chiwan->show();
            }
            //前湾
            else if(floatFlag == 2){
                qianwan->show();
            }
            //前海湾
            else if(floatFlag == 3){
                qianhaiwan->show();
            }
            //宝安中心
            else if(floatFlag == 4){
                baoan->show();
            }
            //西丽
            else if(floatFlag == 5){
                xili->show();
            }
            //大学城
            else if(floatFlag == 6){
                univer->show();
            }
            //深圳北
            else if(floatFlag == 7){
                shenzhenn->show();
            }
            //黄贝岭
            else if(floatFlag == 8){
                huangbeiling->show();
            }
        }
        else{
            //错误输入弹出提示框
            QMessageBox::critical(this, "Error", "请输入有效站点编码");
        }
    });

    //开始购票界面返回主菜单
    startCho = new startChoose;
    connect(startChoBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
            startCho->setGeometry(this->geometry());
            this->hide();
            startCho->show();
        });
        connect(startCho, &startChoose::startChooseBack, this, [=](){
            startCho->hide();
            QTimer::singleShot(50, this, [=](){
                emit this->mapreferBack();
            });
        });
    });
    //监听各地铁站返回信号

    //设置站点：1-8号，赤湾、前湾、前海湾、宝安中心、西丽、大学城、深圳北、黄贝岭
    //1、赤湾
    setBtnStyle(ui->chiWan);
    connect(ui->chiWan, &QPushButton::clicked, this, [=](){
        chiwan->show();
    });
    //监听
    chiwan = new chiWan;
    connect(chiwan, &chiWan::chiwanBack, this ,[=](){
        chiwan->hide();
        QTimer::singleShot(50, this, [=](){
            emit this->mapreferBack();
        });
    });
    connect(chiwan, &chiWan::chiwanTic, this, [=](){
        QTimer::singleShot(50, this, [=](){
            startCho->setGeometry(this->geometry());
            this->hide();
            chiwan->hide();
            startCho->show();
        });
        connect(startCho, &startChoose::startChooseBack, this, [=](){
            startCho->hide();
            QTimer::singleShot(50, this, [=](){
                emit this->mapreferBack();
            });
        });
    });
    //2、前湾
    setBtnStyle(ui->qianWan);
    connect(ui->qianWan, &QPushButton::clicked, this, [=](){
        qianwan->show();
    });
    //监听
    qianwan = new qianWan;
    connect(qianwan, &qianWan::qianwanBack, this ,[=](){
        qianwan->hide();
        QTimer::singleShot(50, this, [=](){
            emit this->mapreferBack();
        });
    });
    connect(qianwan, &qianWan::qianwanTic, this, [=](){
        QTimer::singleShot(50, this, [=](){
            startCho->setGeometry(this->geometry());
            this->hide();
            qianwan->hide();
            startCho->show();
        });
        connect(startCho, &startChoose::startChooseBack, this, [=](){
            startCho->hide();
            QTimer::singleShot(50, this, [=](){
                emit this->mapreferBack();
            });
        });
    });
    //3、前海湾
    setBtnStyle(ui->qianHaiWan);
    connect(ui->qianHaiWan, &QPushButton::clicked, this, [=](){
        qianhaiwan->show();
    });
    //监听
    qianhaiwan = new qianhaiWan;
    connect(qianhaiwan, &qianhaiWan::qianhaiwanBack, this ,[=](){
        qianhaiwan->hide();
        QTimer::singleShot(50, this, [=](){
            emit this->mapreferBack();
        });
    });
    connect(qianhaiwan, &qianhaiWan::qianhaiwanTic, this, [=](){
        QTimer::singleShot(50, this, [=](){
            startCho->setGeometry(this->geometry());
            this->hide();
            qianhaiwan->hide();
            startCho->show();
        });
        connect(startCho, &startChoose::startChooseBack, this, [=](){
            startCho->hide();
            QTimer::singleShot(50, this, [=](){
                emit this->mapreferBack();
            });
        });
    });
    //4、宝安中心
    setBtnStyle(ui->baoAnCenter);
    connect(ui->baoAnCenter, &QPushButton::clicked, this, [=](){
        baoan->show();
    });
    //监听
    baoan = new baoanCenter;
    connect(baoan, &baoanCenter::baoanBack, this ,[=](){
        baoan->hide();
        QTimer::singleShot(50, this, [=](){
            emit this->mapreferBack();
        });
    });
    connect(baoan, &baoanCenter::baoanTic, this, [=](){
        QTimer::singleShot(50, this, [=](){
            startCho->setGeometry(this->geometry());
            this->hide();
            baoan->hide();
            startCho->show();
        });
        connect(startCho, &startChoose::startChooseBack, this, [=](){
            startCho->hide();
            QTimer::singleShot(50, this, [=](){
                emit this->mapreferBack();
            });
        });
    });
    //5、西丽
    setBtnStyle(ui->xiLi);
    connect(ui->xiLi, &QPushButton::clicked, this, [=](){
        xili->show();
    });
    //监听
    xili = new xiLi;
    connect(xili, &xiLi::xiliBack, this ,[=](){
        xili->hide();
        QTimer::singleShot(50, this, [=](){
            emit this->mapreferBack();
        });
    });
    connect(xili, &xiLi::xiliTic, this, [=](){
        QTimer::singleShot(50, this, [=](){
            startCho->setGeometry(this->geometry());
            this->hide();
            xili->hide();
            startCho->show();
        });
        connect(startCho, &startChoose::startChooseBack, this, [=](){
            startCho->hide();
            QTimer::singleShot(50, this, [=](){
                emit this->mapreferBack();
            });
        });
    });
    //6、大学城
    setBtnStyle(ui->univerCity);
    connect(ui->univerCity, &QPushButton::clicked, this, [=](){
        univer->show();
    });
    //监听
    univer = new univerCity;
    connect(univer, &univerCity::univerBack, this ,[=](){
        univer->hide();
        QTimer::singleShot(50, this, [=](){
            emit this->mapreferBack();
        });
    });
    connect(univer, &univerCity::univerTic, this, [=](){
        QTimer::singleShot(50, this, [=](){
            startCho->setGeometry(this->geometry());
            this->hide();
            univer->hide();
            startCho->show();
        });
        connect(startCho, &startChoose::startChooseBack, this, [=](){
            startCho->hide();
            QTimer::singleShot(50, this, [=](){
                emit this->mapreferBack();
            });
        });
    });
    //7、深圳北
    setBtnStyle(ui->shenzhenNorth);
    connect(ui->shenzhenNorth, &QPushButton::clicked, this, [=](){
        shenzhenn->show();
    });
    //监听
    shenzhenn = new shenzhenNorth;
    connect(shenzhenn, &shenzhenNorth::shenzhennorthBack, this ,[=](){
        shenzhenn->hide();
        QTimer::singleShot(50, this, [=](){
            emit this->mapreferBack();
        });
    });
    connect(shenzhenn, &shenzhenNorth::shenzhennorthTic, this, [=](){
        QTimer::singleShot(50, this, [=](){
            startCho->setGeometry(this->geometry());
            this->hide();
            shenzhenn->hide();
            startCho->show();
        });
        connect(startCho, &startChoose::startChooseBack, this, [=](){
            startCho->hide();
            QTimer::singleShot(50, this, [=](){
                emit this->mapreferBack();
            });
        });
    });
    //8、黄贝岭
    setBtnStyle(ui->huangBeiLing);
    connect(ui->huangBeiLing, &QPushButton::clicked, this, [=](){
        huangbeiling->show();
    });
    //监听
    huangbeiling = new huangbeiLin;
    connect(huangbeiling, &huangbeiLin::huangbeilinBack, this ,[=](){
        huangbeiling->hide();
        QTimer::singleShot(50, this, [=](){
            emit this->mapreferBack();
        });
    });
    connect(huangbeiling, &huangbeiLin::huangbeilinTic, this, [=](){
        QTimer::singleShot(50, this, [=](){
            startCho->setGeometry(this->geometry());
            this->hide();
            huangbeiling->hide();
            startCho->show();
        });
        connect(startCho, &startChoose::startChooseBack, this, [=](){
            startCho->hide();
            QTimer::singleShot(50, this, [=](){
                emit this->mapreferBack();
            });
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

mapRefer::~mapRefer()
{
    delete ui;
}
