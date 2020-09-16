#ifndef PAYTIC_H
#define PAYTIC_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class payTic;
}

class payTic : public QWidget
{
    Q_OBJECT

public:
    explicit payTic(QWidget *parent = nullptr);
    ~payTic();

    Ui::payTic *ui;

    //定义总票价
    int endPrice;

    //总票价显示
    QLabel * priceLb = new QLabel(this);

    //接受价格的槽函数
    void getPrice(int price)
    {
        endPrice=price;
    }

    //定义函数判断支付是否成功
    void checkPay(int endPrice, int realPay)
    {
        if(endPrice == realPay)
        {
            //支付成功
            QMessageBox successPay(QMessageBox::Information, "支付完成", "购票成功！");
            successPay.setWindowIcon(QIcon(":/res/cartonIcon.jpg"));
            successPay.setStandardButtons(QMessageBox::Ok);
            successPay.setButtonText(QMessageBox::Ok, QString("确认并返回主菜单"));
            int result = successPay.exec();
            if(result == QMessageBox::Ok)
            {
                emit payBack();
                this->hide();
            }
        }
        else if(endPrice < realPay)
        {
            //支付成功并找零
            int overPaid = realPay - endPrice;
            QString overPaidStr = QString::number(overPaid);
            QMessageBox overPay(QMessageBox::Information, "支付完成", "购票成功，找零"+overPaidStr+"元");
            overPay.setWindowIcon(QIcon(":/res/cartonIcon.jpg"));
            overPay.setStandardButtons(QMessageBox::Ok);
            overPay.setButtonText(QMessageBox::Ok, QString("确认并返回主菜单"));
            int result = overPay.exec();
            if(result == QMessageBox::Ok)
            {
                emit payBack();
                this->hide();
            }

        }
        else
        {
            //金额不足重新支付
            QMessageBox failPay(QMessageBox::Warning, "支付失败", "请确定支付金额并重新支付");
            failPay.setWindowIcon(QIcon(":/res/cartonIcon.jpg"));
            failPay.setStandardButtons(QMessageBox::Ok|QMessageBox::No);
            failPay.setButtonText(QMessageBox::Ok, QString("返回主菜单"));
            failPay.setButtonText(QMessageBox::No, QString("继续支付"));
            int result = failPay.exec();
            if(result == QMessageBox::Ok)
            {
                emit payBack();
                this->hide();
            }
        }
    }


signals:
    //自定义返回主菜单信号
    void payBack();

private:

};



#endif // PAYTIC_H
