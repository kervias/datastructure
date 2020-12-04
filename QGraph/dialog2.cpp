#include "dialog2.h"
#include "ui_dialog2.h"
#include <QDebug>
Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    sig = 0;
    b = 0;
    setWindowTitle("删除结点");
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_buttonBox_accepted()
{
    sig = ui->spinBox->value();
    //qDebug()<<sig;
    b = 1;
}
bool Dialog2::convey_sig(int &sig2)
{
    sig2 = sig;
    qDebug()<<sig2;
    return b;
}

void Dialog2::get_range(int min_v, int max_v)
{
   ui->spinBox->setRange(min_v,max_v);
}

