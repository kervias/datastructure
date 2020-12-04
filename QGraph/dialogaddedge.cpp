#include "dialogaddedge.h"
#include "ui_dialogaddedge.h"

DialogAddEdge::DialogAddEdge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddEdge)
{
    ui->setupUi(this);
    b = 0;
    sig1 = sig2 =0;
    setWindowTitle("添加边");
}

DialogAddEdge::~DialogAddEdge()
{
    delete ui;
}

void DialogAddEdge::on_buttonBox_accepted()
{
    sig1 = ui->spinBox->value();
    sig2 = ui->spinBox_2->value();
    //qDebug()<<sig;
    b = 1;
}

 bool DialogAddEdge::convey_sig(int &sig3,int &sig4)
 {
     sig3 =sig1;
     sig4 = sig2;
     return b;
 }

 void DialogAddEdge::get_range(int min_v, int max_v)
 {
    ui->spinBox->setRange(min_v,max_v);
    ui->spinBox_2->setRange(min_v,max_v);
 }
