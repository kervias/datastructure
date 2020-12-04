#ifndef DIALOGDELETEEDGE_H
#define DIALOGDELETEEDGE_H

#include <QDialog>

namespace Ui {
class DialogDeleteEdge;
}

class DialogDeleteEdge : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDeleteEdge(QWidget *parent = 0);
    void get_range(int min_v,int max_v);
    bool convey_sig(int &sig3,int &sig4);
    ~DialogDeleteEdge();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogDeleteEdge *ui;
    bool b;
    int sig1;
    int sig2;
};

#endif // DIALOGDELETEEDGE_H
