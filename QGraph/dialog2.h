#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    void get_range(int min_v, int max_v);
    bool convey_sig(int &sig2);
    ~Dialog2();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog2 *ui;
    int sig;
    bool b;
};

#endif // DIALOG2_H
