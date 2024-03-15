#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

int money{0};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    changeEnabled();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff) {
    money += diff;
    ui->lcdNumber->display(money);

    changeEnabled();
}

void Widget::changeEnabled() {
    ui->pbReset->setEnabled(money > 0);
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 200);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}

void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{

    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    int m[4] = { 500, 100, 50, 10 };

    QString text = "";

    for (int i = 0; i < 4; i++) {
        int change = money / m[i];
        money %= m[i];

        if (change != 0) text.append(QString("%1원   %2개\n").arg(m[i]).arg(change));
    }

    changeMoney(-money);
    QMessageBox mb;
    mb.information(nullptr, "title", text);
}
