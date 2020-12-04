#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <cstring>
#include <iostream>
using namespace std;

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();
    bool getData(string &s,int &n1,int &n2);
protected:

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog1 *ui;
    string Filename;
    int rad1;
    int rad2;
    bool b;
};

#endif // DIALOG1_H
