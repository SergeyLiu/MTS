#include "mainscene.h"
#include "ui_mainscene.h"


mainScene::mainScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainScene)
{
    ui->setupUi(this);

    //配置界面
    //设置标题
    setWindowTitle("主菜单");
    //设置固定大小
    setFixedSize(960, 720);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));
    //设置按钮位置
    ui->startBtn->move(380, 120);
    ui->referBtn->move(380, 320);
    ui->existBtn->move(380, 520);

    //购票按钮实现
    startCho = new startChoose;
    connect(ui->startBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
            changeWidget(this, startCho);
        });
    });
    //监听开始购票场景返回信号
    connect(startCho, &startChoose::startChooseBack, this, [=](){
        this->setGeometry(startCho->geometry());
        changeWidget(startCho, this);
    });


    //地图查询按钮实现
    mapRef = new mapRefer;
    connect(ui->referBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
            mapRef->setGeometry(this->geometry());
            changeWidget(this, mapRef);
        });
    });
    //监听地图查询场景返回信号
    connect(mapRef, &mapRefer::mapreferBack, this, [=](){
        this->setGeometry(mapRef->geometry());
        changeWidget(mapRef, this);
    });
    //退出按钮实现
    connect(ui->existBtn, &QPushButton::clicked, this, [=](){
        this->close();
    });
}

//重写paintEvent事件
void mainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/Icon.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

mainScene::~mainScene()
{
    delete ui;
}
