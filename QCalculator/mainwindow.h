#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <cstring>
#include <QMainWindow>
#include <QPushButton>
#include <iostream>
#include <stack>
#include <cmath>
#include <ctype.h>
#include <QKeyEvent>
using namespace std;


struct node
{
    int a1;
    double ans;
};

class calculator
{
    public:
    void get_string(string s);  //获取计算式并操作
    void judge_error(string s);  //判断输入合法性
    void translate();  //处理数字
    int priority(char ch);  //优先级判断
    void cc_top2(stack<double> &s,char ch);  //计算取出栈顶两个元素进行计算
    node recur_cc(int m);    // 递归运算
    double cc_answer();  //计算并得到结果
    private:
    double answer;  //计算结果
    string ccstr;  //表达式
};



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *e);


private slots:
    void on_a1_clicked();

    void on_a8_clicked();

    void on_a2_clicked();

    void on_a3_clicked();

    void on_a4_clicked();

    void on_a5_clicked();

    void on_a6_clicked();

    void on_a7_clicked();

    void on_a9_clicked();

    void on_a0_clicked();

    void on_b5_clicked();

    void on_b6_clicked();

    void on_b7_clicked();

    void on_b1_clicked();

    void on_b2_clicked();

    void on_b3_clicked();

    void on_b4_clicked();

    void on_c1_clicked();

    void on_c2_clicked();

    void on_c3_clicked();

    void on_c_clicked();

    void on_b8_clicked();

    void on_b9_clicked();

    void on_a0_2_clicked();

    void on_a0_3_clicked();

private:
    Ui::MainWindow *ui;
     string str;
     string st;
     QString sr;
     calculator cc;
};

#endif // MAINWINDOW_H
