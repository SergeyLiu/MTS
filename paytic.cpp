#include "paytic.h"
#include "ui_paytic.h"



payTic::payTic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::payTic)
{
    ui->setupUi(this);
    //配置场景
    //设置标题
    setWindowTitle("支付");
    //设置固定大小
    setFixedSize(480, 360);
    //设置图标
    setWindowIcon(QIcon(":/res/cartonIcon.jpg"));

    //设置返回主菜单按钮
    ui->backBtn->setText("返回主菜单");
    ui->backBtn->move(0, this->height()-ui->backBtn->height());
    connect(ui->backBtn, &QPushButton::clicked, this, [=](){
        emit payBack();
        this->hide();
    });

    //确认支付按钮
    QPushButton * payBtn = new QPushButton(this);
    payBtn->resize(100, 40);
    payBtn->setText("确认支付");
    payBtn->move(this->width()-payBtn->width(), this->height()-payBtn->height());
    connect(payBtn, &QPushButton::clicked, this, [=](){
        int realPay = ui->lineEdit->text().toInt();
        checkPay(endPrice, realPay);
    });

    //设置界面字体
    ui->AllpayLb->setStyleSheet("font:bold 20px;");
    priceLb->setStyleSheet("font:bold 20px;");
    priceLb->resize(40, 50);
    priceLb->move(100, 0);
    ui->MypayLb->setStyleSheet("font:bold 20px;");
    ui->lineEdit->setStyleSheet("font:bold 20px;");
    ui->yuan1->setStyleSheet("font:bold 20px;");


}

payTic::~payTic()
{
    delete ui;
}
