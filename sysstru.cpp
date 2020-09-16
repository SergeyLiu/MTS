#include "sysstru.h"
#include "ui_sysstru.h"

sysStru::sysStru(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sysStru)
{
    ui->setupUi(this);
    //配置场景
    //设置标题
    setWindowTitle("系统说明");
    //设置固定大小
    setFixedSize(960, 720);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));
    //设置字体
    QFont font("Microsoft YaHei", 22, 75);
    //购票流程
    QLabel * process = new QLabel;
    process->setParent(this);
    process->resize(150, 60);
    process->setFont(font);
    process->setText("购票流程");

    //创建下一步按钮
    QPushButton * nextBtn = new QPushButton;
    nextBtn->setParent(this);
    nextBtn->resize(200, 80);
    nextBtn->move(this->width()-nextBtn->width(), this->height()-nextBtn->height());
    nextBtn->setText("下一步");
    nextBtn->show();

    //实例化主菜单窗口
    MScene = new mainScene;

    //点击下一步进入主菜单
    connect(nextBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                            MScene->setGeometry(this->geometry());
                            this->hide();
                            MScene->show();
                         });
    });
}

sysStru::~sysStru()
{
    delete ui;
}
