#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbcoffee->setEnabled(false); //disable the button first.
    ui->pbtea->setEnabled(false);
    ui->pbgongcha->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int n){
    money += n;
  ui->lcdNumber->display(QString::number(money)); //display current money
  if(money>=100){
      ui->pbcoffee->setEnabled(true);
  }
 if(money>=150){
      ui->pbtea->setEnabled(true);
  }
  if(money>=200){
      ui->pbgongcha->setEnabled(true);
  }
  if(money<100){
      ui->pbcoffee->setEnabled(false);
  }
 if(money<150){
      ui->pbtea->setEnabled(false);
  }
  if(money<200){
      ui->pbgongcha->setEnabled(false);
  }

}
void Widget::on_pb10_clicked()
{
    changeMoney(10);

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

void Widget::on_pbcoffee_clicked()
{
    changeMoney(-100);
    //ui->pbcoffee->setEnabled(false);
}

void Widget::on_pbtea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbgongcha_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbrefund_clicked()
{
    QMessageBox msg;
    int m500=0; //count 500won
    int m100=0;
    int m50=0;
    int m10=0;
    m500 = money / 500; changeMoney(-500*m500);
    m100 = money / 100; changeMoney(-100*m100);
    m50 = money / 50; changeMoney(-50*m50);
    m10 = money / 10; changeMoney(-10*m10);

    ui->lcdNumber->display(QString::number(money));
    msg.information(nullptr,"refund!",QString("500won : %1/ 100won : %2\n  50won : %3/ 10won : %4").arg(QString::number(m500))
                    .arg(QString::number(m100))
                    .arg(QString::number(m50))
                    .arg(QString::number(m10)));
}
