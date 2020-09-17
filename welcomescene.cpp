#include "welcomescene.h"
#include "ui_welcomescene.h"


welcomeScene::welcomeScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::welcomeScene)
{
    ui->setupUi(this);

    //配置场景
    //设置标题
    setWindowTitle("欢迎");
    //设置固定大小
    setFixedSize(960, 720);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));

    //实例化系统说明场景
    sysScene = new sysStru;
    //点击下一步进入场景
    connect(ui->nextBtn, &QPushButton::clicked, [=](){
        QTimer::singleShot(50, this, [=](){
                            //设置chooseScene场景的位置
                            sysScene->setGeometry(this->geometry());
                            //进入到选择关卡的场景中
                            //自身隐藏
                            this->hide();
                            //显示选择关卡场景
                            sysScene->show();
                         });
    });
}

//重写paintEvent事件
void welcomeScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/weilcome.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

welcomeScene::~welcomeScene()
{
    delete ui;
}
