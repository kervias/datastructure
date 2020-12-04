#include "dialogdeleteedge.h"
#include "ui_dialogdeleteedge.h"

DialogDeleteEdge::DialogDeleteEdge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDeleteEdge)
{
    ui->setupUi(this);
    b = 0;
    sig1 = sig2 =0;
    setWindowTitle("删除边");
}

DialogDeleteEdge::~DialogDeleteEdge()
{
    delete ui;
}

bool DialogDeleteEdge::convey_sig(int &sig3,int &sig4)
{
    sig3 =sig1;
    sig4 = sig2;
    return b;
}

void DialogDeleteEdge::on_buttonBox_accepted()
{
    sig1 = ui->spinBox->value();
    sig2 = ui->spinBox_2->value();
    b = 1;
}

void DialogDeleteEdge::get_range(int min_v, int max_v)
{
    ui->spinBox->setRange(min_v,max_v);
    ui->spinBox_2->setRange(min_v,max_v);
}

