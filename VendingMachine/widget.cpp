#include "widget.h"
#include "ui_widget.h"
#include <string>
#include <QMessageBox>
#include <QString>


using std::to_string;
using std::string;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::onEnable(){
    if(money <  100){
        ui->PbCoffee->setEnabled(false);
    }
    if(money >= 100){
        ui->PbCoffee->setEnabled(true);
    }
    if(money < 150){
        ui->PbTee->setEnabled(false);
    }
    if(money >= 150){
        ui->PbTee->setEnabled(true);
    }
    if(money < 200){
        ui->PbMilk->setEnabled(false);
    }
    if(money >= 200){
        ui->PbMilk->setEnabled(true);
    }



}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    onEnable();

}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_lcdNumber_overflow()
{

}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_PbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_PbTee_clicked()
{
    changeMoney(-150);
}


void Widget::on_PbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_PbReset_clicked()
{
    QMessageBox mb;
    

    money_500 = money / 500;
    money = money % 500;
    money_100 = money / 100;
    money = money % 100;
    money_50 = money / 50;
    money = money % 50;
    money_10 = money / 10;
    money = money % 10;


    QString app_str;

    app_str = QString("500 %1. 100 %2. 50 %3. 10 %4")
                  .arg(QString::number(money_10))
                  .arg(QString::number(money_50))
                  .arg(QString::number(money_100))
                  .arg(QString::number(money_500));


    mb.information(nullptr, "title", app_str);



}

