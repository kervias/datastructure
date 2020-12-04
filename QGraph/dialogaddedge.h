#ifndef DIALOGADDEDGE_H
#define DIALOGADDEDGE_H

#include <QDialog>

namespace Ui {
class DialogAddEdge;
}

class DialogAddEdge : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddEdge(QWidget *parent = 0);
    void get_range(int min_v, int max_v);
    bool convey_sig(int &sig3,int &sig4);
    ~DialogAddEdge();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogAddEdge *ui;
    bool b;
    int sig1;
    int sig2;
};

#endif // DIALOGADDEDGE_H
