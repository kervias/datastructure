#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog1.h"
#include "dialog2.h"
#include "dialogaddedge.h"
#include "dialogdeleteedge.h"
#include "graph1.h"
#include "graph2.h"
#include "help.h"
#include <QDialog>
#include <QPushButton>
#include <iostream>
#include <vector>
#include <QPoint>
#include <QMouseEvent>
#include <QPaintEvent>
#include <Qpainter>
#include <QBrush>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //void drawVertex(int n);
    void mousePressEvent(QMouseEvent *e);
    void showButton();   //画顶点

    void paintEvent(QPaintEvent *);


private slots:
    void on_newFile1_triggered();

    void on_addVerex_triggered();

    void on_deletVertex_triggered();

    void on_addEdge_triggered();

    void on_deletedge_triggered();

    void on_saveFile_triggered();

    void on_openFile_triggered();

    void on_newFile2_triggered();

    void on_save2File_triggered();

    void on_aboutAction_triggered();

private:
    Ui::MainWindow *ui;
    Dialog1 *D1;
    Dialog2 *D2;
    DialogAddEdge *D3;
    DialogDeleteEdge *D4;
    vector<graph1*> vec1;
    vector<graph2*> vec2;
    int BBB;
    QPushButton *pbutton;
};

#endif // MAINWINDOW_H
