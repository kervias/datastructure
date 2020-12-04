#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstring>
#include <QPushButton>
#include <iostream>
#include <math.h>
#include <sstream>
#include <ctype.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowTitle("计算器");
    ui->setupUi(this);
    ui->qscreen->setText("0");
    ui->screen->setText("0");
    ui->screen2->setText("☺☺");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_a1_clicked()
{
    if(str.size() == 0 || str[str.size()-1] != ')' || isdigit(str[str.size()-1]))
    {
        ui->screen2->setText("☺☺");
        str += '1';
        st +='1';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_a2_clicked()
{
    if(str.size() == 0 || str[str.size()-1] != ')' || isdigit(str[str.size()-1]))
    {
        ui->screen2->setText("☺☺");
        str += '2';
        st += '2';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);


}

void MainWindow::on_a3_clicked()
{
    if(str.size() == 0 || str[str.size()-1] != ')' || isdigit(str[str.size()-1]))
    {
        ui->screen2->setText("☺☺");
        str += '3';
        st += '3';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_a4_clicked()
{
    if(str.size() == 0 || str[str.size()-1] != ')' || isdigit(str[str.size()-1]))
    {
        ui->screen2->setText("☺☺");
        str += '4';
        st += '4';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_a5_clicked()
{
    if(str.size() == 0 || str[str.size()-1] != ')' || isdigit(str[str.size()-1]))
    {
        ui->screen2->setText("☺☺");
        str += '5';
        st += '5';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_a6_clicked()
{
    if(str.size() == 0 || str[str.size()-1] != ')' || isdigit(str[str.size()-1]))
    {
        ui->screen2->setText("☺☺");
        str += '6';
        st += '6';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_a7_clicked()
{
    if(str.size() == 0 || str[str.size()-1] != ')' || isdigit(str[str.size()-1]))
    {
        ui->screen2->setText("☺☺");
        str += '7';
        st += '7';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_a8_clicked()
{
    if(str.size() == 0 || str[str.size()-1] != ')' || isdigit(str[str.size()-1]))
    {
        ui->screen2->setText("☺☺");

        str += '8';
        st += '8';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_a9_clicked()
{
    if(str.size() == 0 || str[str.size()-1] != ')' || isdigit(str[str.size()-1]))
    {
        ui->screen2->setText("☺☺");
        str += '9';
        st += '9';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_a0_clicked()
{
    if(str.size() == 0 || str[str.size()-1] != ')' || isdigit(str[str.size()-1]))
    {
        ui->screen2->setText("☺☺");
        str += '0';
        st += '0';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_b5_clicked()
{
    if(str.size() == 0 || (str[str.size()-1] != ')' && str[str.size()-1] != '!' && isdigit(str[str.size()-1]) == 0))
    {
        ui->screen2->setText("☺☺");
        str += '!';
        st += '!';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}


void MainWindow::on_b6_clicked()
{
    if(str.size() != 0 && (str[str.size()-1] == ')' || isdigit(str[str.size()-1])))
    {
        ui->screen2->setText("☺☺");
            str += "||";
            st += '|';
            ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_b7_clicked()
{
    if(str.size() != 0 && (str[str.size()-1] == ')' || isdigit(str[str.size()-1])))
    {
        ui->screen2->setText("☺☺");
            str += "&&";
            st += '&';
            ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);


}

void MainWindow::on_b8_clicked()
{
    if(str.size() == 0 || (str[str.size()-1] != ')' && isdigit(str[str.size()-1]) == 0))
    {
        ui->screen2->setText("☺☺");
       str += '(';
       st += '(';
       ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_b9_clicked()
{
    if(str.size() != 0 && ((str[str.size()-1] == ')' || isdigit(str[str.size()-1]))))
    {
        ui->screen2->setText("☺☺");
        str += ')';
        st += ')';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_b1_clicked()
{
    if(str.size() == 0 || str[str.size()-1] == '(' || str[str.size()-1] == ')' || isdigit(str[str.size()-1]))
    {
        ui->screen2->setText("☺☺");
        str += '+';
        st += '+';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
         ui->screen2->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_b2_clicked()
{
    if(str.size() == 0 || str[str.size()-1] == '(' || str[str.size()-1] == ')' || isdigit(str[str.size()-1]))
    {
        ui->screen2->setText("☺☺");
        str += '-';
        st += '-';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_b3_clicked()
{
    if(str.size() != 0 &&(str[str.size()-1] == ')' || isdigit(str[str.size()-1])))
    {
        ui->screen2->setText("☺☺");
        str += '*';
        st += '*';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
         ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);


}

void MainWindow::on_b4_clicked()
{
    if( str.size() != 0 &&(str[str.size()-1] == ')' || isdigit(str[str.size()-1])))
    {
        ui->screen2->setText("☺☺");
        str += '/';
        st += '/';
        ui->qscreen->setText(QString::fromStdString(str));
    }
    else
        ui->screen2->setText("☹☹\n语法错误");
    ui->screen2->setAlignment(Qt::AlignCenter);

}

void MainWindow::on_c1_clicked()
{
    if(str.size() != 0)
    {
        ui->screen2->setText("☺☺");
        if(str[str.size()-1] == '&' || str[str.size()-1] == '|')
        {
            str.erase(str.size()-1,1);
        }
        str.erase(str.size()-1,1);
        st.erase(st.size()-1,1);
        ui->qscreen->setText(QString::fromStdString(str));
    }
    ui->screen2->setAlignment(Qt::AlignCenter);

    //ui->qscreen->setText(QString::fromStdString(str));
}

void MainWindow::on_c2_clicked()
{
    str.clear();
    st.clear();
    ui->screen2->setText("☺☺");
    ui->screen2->setAlignment(Qt::AlignCenter);
    ui->qscreen->setText("0");
}

void MainWindow::on_c3_clicked()
{
    close();
}

void MainWindow::on_c_clicked()
{
    if(st.size() != 0 && (st[st.size()-1] == ')' || isdigit(st[st.size()-1])))
    {
        int a=0;
        char cs;
        for(int j=0; j<st.size(); j++)
        {
            if(st[j] == '(') a++;
            if(st[j] == ')') a--;
        }
        if(a == 0)
        {
            cc.get_string(st);
              double as=cc.cc_answer();
                if((as-int(as)) != 0.0)
                {
                    sr = QString::number(as,10,8);
                    if(sr[0] == 'i')
                    {
                        ui->screen2->setText("分母为0\n计算无效");
                    }
                    else
                    ui->screen->setText(sr);
                }
                else
                {
                    sr = QString::number(int(as),10);
                    //sr = '='+sr;
                    ui->screen2->setText("☺☺");
                    ui->screen2->setAlignment(Qt::AlignCenter);
                    ui->screen->setText(sr);
                }
                str.clear();
                st.clear();

        }
        else
        {
            ui->screen2->setText("☹  ☹\n括号多余");
        }

    }
    else
    {
        if(st.size()!= 0 && isdigit(st.size()-1) == 0)
        {
            ui->screen2->setText("☹  ☹\n无效输入");
        }
    }
    ui->screen2->setAlignment(Qt::AlignCenter);

}
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    string s = e->text().toStdString();
    //ui->qscreen->setText(QString::fromStdString(str));
    int num=1;
    if(s == "0") {on_a0_clicked();num = 0;}
    if(s == "1") {on_a1_clicked();num = 0;}
   if(s == "2") {on_a2_clicked();num = 0;}
   if(s == "3") {on_a3_clicked();num = 0;}
   if(s == "4") {on_a4_clicked();num = 0;}
   if(s == "5") {on_a5_clicked();num = 0;}
   if(s == "6") {on_a6_clicked();num = 0;}
   if(s == "7") {on_a7_clicked();num = 0;}
   if(s == "8") {on_a8_clicked();num = 0;}
   if(s == "9") {on_a9_clicked();num = 0;}
   if(s == "+") {on_b1_clicked();num = 0;}
   if(s == "-") {on_b2_clicked();num = 0;}
   if(s == "*") {on_b3_clicked();num = 0;}
   if(s == "/") {on_b4_clicked();num = 0;}
   if(s == "!") {on_b5_clicked();num = 0;}
   if(s == "|") {on_b6_clicked();num = 0;}
   if(s == "&") {on_b7_clicked();num = 0;}
   if(s == "(") {on_b8_clicked();num = 0;}
   if(s == "") num=0;
   if(s == ")") {on_b9_clicked();num = 0;}
   if(s == "\b") {on_c1_clicked();num = 0;}
   if(s == "\u007F") {on_c2_clicked();num=0;}
   if(s == "\r" || s == "=") {on_c_clicked();num = 0;}
   if(num == 1)
   {
       QString text = QString("未知字符\n    %1").arg(e->text());
       ui->screen2->setText(text);
       ui->screen2->setAlignment(Qt::AlignCenter);
   }
   /* switch(s)
    {
       case "0":on_a0_clicked();break;
       case "1":on_a1_clicked();break;
       case "2":on_a2_clicked();break;
       case "3":on_a3_clicked();break;
       case "4":on_a4_clicked();break;
       case "5":on_a5_clicked();break;
       case "6":on_a6_clicked();break;
       case "7":on_a7_clicked();break;
       case "8":on_a8_clicked();break;
       case "9":on_a9_clicked();break;
       case "*":on_b3_clicked();break;
       case "-":on_b2_clicked();break;
       case "+":on_b1_clicked();break;
       case "/":on_b4_clicked();break;
       case "(":on_b8_clicked();break;
       case ")":on_b9_clicked();break;
       case "!":on_b5_clicked();break;
       case "&":on_b6_clicked();break;
       case "|":on_b7_clicked();break;
       case "\b":on_c1_clicked();break;
       case "\r":on_c_clicked();break;
       default:ui->screen2->setText("未知字符%1").arg(e->text());
    }*/
}

int calculator::priority(char ch)
{
    switch (ch)
    {
        case '#':return 0;
        case '+':return 2;
        case '-':return 2;
        case '*':return 3;
        case '/':return 3;
        case '(':return 4;
        case ')':return 4;
        case '!':return 10;
        case '&':return 1;
        case '|':return 1;
        //default:cout<<"警告：输入了错误运算符'"<<ch<<"'!"<<endl;exit(0);
    }
}

void calculator::get_string(string s)
{
    ccstr = s;
    judge_error(s);
    ccstr = '(' + ccstr;
    ccstr = ccstr + ')';
}

void calculator::judge_error(string s)
{

    //处理  !!!的问题
}
void calculator::cc_top2(stack<double> &s,char c)
{
    double x1,temp;
    switch (c)
    {
        case '+':temp = s.top();s.pop();x1 = s.top();x1 += temp;break;
        case '-':temp = s.top();s.pop();x1 = s.top();x1 -= temp;break;
        case '*':temp = s.top();s.pop();x1 = s.top();x1 *= temp;break;
        case '/':temp = s.top();s.pop();x1 = s.top();x1 /= temp;break;
        case '!':x1 = s.top();x1 = !x1;break;
        case '|':temp = s.top();s.pop();x1 = s.top();x1 = (temp || x1);break;
        case '&':temp = s.top();s.pop();x1 = s.top();x1 = (temp && x1);break;
    }
    s.pop();
    s.push(x1);
}
node calculator::recur_cc(int m)
{
    stack<double> stk1;  //数字栈
    stack<char> stk2;   //运算符栈
    node q;
    stk2.push('#');
    double sum;
    char ch;
    int t;
    if(ccstr[m+1] == '-'|| ccstr[m+1] == '+') stk1.push(0);
    for(int i=m+1; i<ccstr.size(); i++)
    {
        sum =0.0;
        t=0;
        while(i<ccstr.size() && isdigit(char(ccstr[i])))
        {
            sum = sum*10 + (char(ccstr[i] - '0'));
            i++;
            t=1;
        }
        if(t)
        stk1.push(sum);
        if(ccstr[i] == '(')
        {
            q = recur_cc(i);
            stk1.push(q.ans);
            i = q.a1;
            continue;
        }
        if(ccstr[i] == ')')
        {
            ch = stk2.top();
            while(ch != '#')
            {
                cc_top2(stk1,ch);
                stk2.pop();
                ch = stk2.top();
            }
            q.ans = stk1.top();
            q.a1 = i;
            stk1.pop();
            return q;
        }
        ch = stk2.top();
        while(priority(ccstr[i]) <= priority(ch))
        {
            cc_top2(stk1,ch);
            stk2.pop();
            ch = stk2.top();
        }
        stk2.push(ccstr[i]);
    }
}

double calculator::cc_answer()
{
    node p;
    p = recur_cc(0);
    return p.ans;
}

void MainWindow::on_a0_2_clicked()
{
    ui->screen2->setText("装饰！\n没啥用");
    ui->screen2->setAlignment(Qt::AlignCenter);
}

void MainWindow::on_a0_3_clicked()
{
    ui->screen2->setText("装饰！\n没啥用");
     ui->screen2->setAlignment(Qt::AlignCenter);
}
