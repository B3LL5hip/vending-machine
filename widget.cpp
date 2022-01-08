#include <QMessageBox>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 100);
    ui->pbReset->setEnabled(money > 0);
}

int Widget::resetMoney(int coin)
{
    int num = 0;
    if(money >= coin){
        num = money / coin;
        money %= coin;
    }

    return num;
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);

}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);

}


void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);

}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);

}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);

}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);

}


void Widget::on_pbReset_clicked()
{
    QMessageBox msgBox;
    int coin[4] = {500, 100, 50, 10};
    QString msg = "";


    for(int i = 0; i < 4; i++){
        int tmp = resetMoney(coin[i]);
        if(tmp){
            msg += QString::number(coin[i]) + "원 : " + QString::number(tmp) + "개\n";
        }
    }
    msg += "반환되었습니다.";

    changeMoney(money);
    msgBox.information(NULL, "Reset", msg, msgBox.Ok);

}

