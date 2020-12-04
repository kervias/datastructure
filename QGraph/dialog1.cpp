#include "dialog1.h"
#include "ui_dialog1.h"
#include <QDebug>
#include <QRadioButton>

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    setWindowTitle("新建存储图");
    b = 0;
    ui->lineEdit->setText("未命名*.Qtxt");
    ui->radioButton->setChecked(true);
    ui->radioButton_3->setChecked(true);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_buttonBox_accepted()
{
    QString qstr = QString(ui->lineEdit->text());
    Filename = qstr.toStdString();
    if(ui->radioButton->isChecked())
    {
        rad1 = 0;

    }

    if(ui->radioButton_2->isChecked())
    {
        rad2 = 1;
    }

    if(ui->radioButton_3->isChecked())
    {
        rad2 = 0;

    }

    if(ui->radioButton_4->isChecked())
    {
        rad2 = 1;
    }
    b = 1;
}

bool Dialog1::getData(string &s, int &n1,int &n2)
{
    s = Filename;
    n1 = rad1;
    n2 = rad2;
    return b;
}
