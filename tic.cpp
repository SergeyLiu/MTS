#include "tic.h"
#include "ui_tic.h"


extern int startFlag;
extern int endFlag;


Tic::Tic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tic)
{
    ui->setupUi(this);


    //配置场景
    //设置标题
    setWindowTitle("选择票数");
    //设置固定大小
    setFixedSize(960, 720);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));

    //设置返回按钮
    QPushButton * TicBackBtn = new QPushButton(this);
    TicBackBtn->resize(200, 80);
    TicBackBtn->setText("返回主菜单");
    TicBackBtn->move(0, this->height()-TicBackBtn->height());
    //点击返回后延时发送返回信号
    connect(TicBackBtn, &QPushButton::clicked, this, [=](){
        QTimer::singleShot(50, this, [=](){
                    emit this->ticBack();
                });
    });

    //设置购票按钮
    QPushButton * payBtn = new QPushButton(this);
    payBtn->resize(200, 80);
    payBtn->setText("购票");
    payBtn->move(760, 640);
    //支付窗口
    paytic = new payTic;
    //连接返回信号
    connect(paytic, &payTic::payBack, this, &Tic::ticBack);
    connect(this, &Tic::sendPrice, paytic, &payTic::getPrice);
    connect(payBtn, &QPushButton::clicked, this, [=](){
        //票数获取
       int ticNum = ui->TicSpinBox->value();
       //票价计算
       int ticPrice = calcPrice(stationCount);
       //发出信号
       int endPrice = ticNum * ticPrice;
       emit this->sendPrice(endPrice);
       QString priceStr = QString::number(endPrice) + "元";
       paytic->priceLb->setText(priceStr);
       paytic->setAttribute(Qt::WA_ShowModal, true);
       paytic->ui->lineEdit->setText(QString::number(endPrice));
       paytic->show();
    });

    //显示购票信息
    ui->startLb->setStyleSheet("font:bold 20px;");
    ui->endLb->setStyleSheet("font:bold 20px;");
    ui->throughLb->setStyleSheet("font:bold 20px;");



    //票数选择
    ui->TicLb->setStyleSheet("font:bold 20px;");
    ui->TicSpinBox->setMinimum(1);
    ui->TicSpinBox->setStyleSheet("font:bold 20px;");

    ui->backLb->setStyleSheet("font:bold 20px;");

}

void Tic::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape)
    {
        QMessageBox backTic(QMessageBox::Information, "ESC", "选择返回页面");
        backTic.setWindowIcon(QIcon(":/res/cartonIcon.jpg"));
        backTic.setStandardButtons(QMessageBox::Ok|QMessageBox::No);
        backTic.setButtonText(QMessageBox::Ok, QString("返回主菜单"));
        backTic.setButtonText(QMessageBox::No, QString("重新选择站点"));
        int result = backTic.exec();
        if(result == QMessageBox::Ok)
        {
            //返回主菜单
            QTimer::singleShot(50, this, [=](){
                emit this->ticBack();
            });
        }
        else
        {
            //返回选择始发站界面
            QTimer::singleShot(50, this, [=](){
                emit this->backChoose();
            });
        }
    }
}

Tic::~Tic()
{
    delete ui;
}
