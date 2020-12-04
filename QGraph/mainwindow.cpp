#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QFileInfo>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("未打开文件");
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    BBB = 0;
    setWindowTitle("Mini图结构");
    //QObject::connect(ui->undoAction,SIGNAL(triggered()),this,SLOT(undo()));
    /*ui->lineEdit->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit->setText("文件");*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newFile1_triggered()  //新建文件
{
    if(vec1.size()!=0 || vec2.size()!=0)
    {
        QMessageBox::information(this, "Error", "只能对一个文件进行操作");
        return;
    }
    D1 = new Dialog1(this);
    D1->setModal(true);
    D1->exec();
    string s;
    int t1=0;
    int t2=0;
    bool B = D1->getData(s,t1,t2);
    if(B)
    {
        graph1* g=new graph1(s,t1,t2);
        ui->label->setText("正在编辑图");
        ui->label_3->setText(("文件名:"+s).data());
        ui->label_4->setText("属性1:静态存储图");
        QString s1 = QString("属性2:");
        if(t1 == 0)
        {
            s1 = s1 + "无向图";
        }
        else
        {
            s1 += "有向图";
        }
        QString s2 = "属性3:";
        if(t2 == 0)
        {
            s2 += "无权图";
        }
        else
        {
            s2 += "加权图";
        }
        ui->label_5->setText(s1);
        ui->label_6->setText(s2);
        ui->label->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->label_4->show();
        ui->label_5->show();
        ui->label_6->show();
        vec1.push_back(g);
    }
}

void MainWindow::on_addVerex_triggered()
{
    if(vec1.size() == 0 && vec2.size() == 0)
    {
        QMessageBox::information(this, "Error", "未新建文件!!");
        return;
    }
    BBB = 1;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        switch (BBB)
        {
        case 1:
        {
            if(e->x() <= 172 || e->x() >=1355 ||e->y() <= 81 || e->y() >= 672)
            {
                QMessageBox::information(this, "Error", "选取点的位置不规范!!");
                BBB = 0;
                return;
            }
            QPoint ppoint = e->pos();
            pbutton = new QPushButton;
            pbutton->setParent(this);
            pbutton->resize(30,30);
            pbutton->move(ppoint);
            pbutton->setStyleSheet("background-color: rgb(116, 215, 47);");
            if(vec2.size()!=0)
            {
                vec2[0]->add_DVertex();
                vec2[0]->vecbutton.push_back(pbutton);
            }
            if(vec1.size()!=0)
            {
                 vec1[0]->add_vertex();
                 vec1[0]->vecbutton.push_back(pbutton);
            }
            showButton();
            BBB = 0;

            break;
        }
        case 2:
        {
            qDebug()<<e->x();
            qDebug()<<e->y();
        }
        default:
            break;
        }
    }





}
void MainWindow::showButton()
{
    if(vec1.size()!=0)
    {
        for(int i=0; i<vec1[0]->vecbutton.size(); i++)
        {
            vec1[0]->vecbutton[i]->setText(QString::number(i+1));
            qDebug()<<vec1.size();
            vec1[0]->vecbutton[i]->show();
        }
    }
    if(vec2.size()!=0)
    {
        for(int i=0; i<vec2[0]->vecbutton.size(); i++)
        {
            vec2[0]->vecbutton[i]->setText(QString::number(i+1));
            vec2[0]->vecbutton[i]->show();
        }
    }
}

void MainWindow::on_deletVertex_triggered()
{
    if(vec1.size() == 0 && vec2.size() == 0)
    {
        QMessageBox::information(this, "Error", "未新建文件!!");
        return;
    }
    int sig;
    if(vec1.size() != 0)
    {
        if( vec1[0]->VertexNum == 0)
        {
            QMessageBox::information(this, "Error", "顶点数为0,无法删除");
            return;
        }
        D2 = new Dialog2(this);
        D2->get_range(1,vec1[0]->VertexNum);
        D2->setModal(true);
        D2->exec();
        bool bs = D2->convey_sig(sig);
        if(bs)
        {
                vec1[0]->vecbutton[sig-1]->hide();
                vec1[0]->delete_vertex(sig);
                update();
                vec1[0]->vecbutton.erase(vec1[0]->vecbutton.begin()+sig-1);
                showButton();
        }
    }
    else
    {
        if( vec2[0]->DVertexNum == 0)
        {
            QMessageBox::information(this, "Error", "顶点数为0,无法删除");
            return;
        }
        D2 = new Dialog2(this);
        D2->get_range(1,vec2[0]->DVertexNum);
        D2->setModal(true);
        D2->exec();
        bool bs = D2->convey_sig(sig);
        if(bs)
        {
            //qDebug()<<"顶点数";
                qDebug()<<vec2[0]->DVertexNum;
                vec2[0]->vecbutton[sig-1]->hide();
                pbutton = vec2[0]->vecbutton[sig-1];
                vec2[0]->delete_DVertex(sig);
                vec2[0]->vecbutton.erase(vec2[0]->vecbutton.begin()+sig-1);
                delete pbutton;
                update();

                showButton();
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p;
    p.begin(this);
    QPen pen;
    pen.setWidth(1);  //设置线宽
    pen.setColor(Qt::blue);
    p.setPen(pen);
    if(vec1.size() != 0)
    {
        int **P = vec1[0]->return_p();
        for(int i=0; i<vec1[0]->VertexNum; i++)
        {
            for(int j=0; j<vec1[0]->VertexNum; j++)
            {
                if(P[i][j])
                {
                    QPoint p3(15,15);
                    QPoint p1 = vec1[0]->vecbutton[i]->pos();
                    p1=p1 + p3;
                    QPoint p2 = vec1[0]->vecbutton[j]->pos();
                    p2=p2+p3;
                    p.drawLine(p1,p2);
                }
            }
        }
    }
    if(vec2.size() != 0)
    {
        for(int i=0; i<vec2[0]->DVertexNum;i++)
        {
            node *pp = vec2[0]->Dvect[i].pnext->next;
            while(pp != NULL)
            {
                QPoint p3(15,15);
                QPoint p1 = vec2[0]->vecbutton[i]->pos();
                p1=p1 + p3;
                QPoint p2 = vec2[0]->vecbutton[pp->adjvex-1]->pos();
                p2=p2+p3;
                p.drawLine(p1,p2);
                pp = pp->next;
            }

        }
    }
    p.end();
}

void MainWindow::on_addEdge_triggered()
{
    if(vec1.size() == 0 && vec2.size() == 0)
    {
        QMessageBox::information(this, "Error", "未新建文件!!");
        return;
    }
    int sig1,sig2; 
    if(vec1.size()!=0)
    {
        if(vec1[0]->VertexNum < 2)
        {
            QMessageBox::information(this, "Error", "顶点数小于2\n无法建立边!!");
            return;
        }
        D3 = new DialogAddEdge(this);
        D3->get_range(1,vec1[0]->VertexNum);
        D3->setModal(true);
        D3->exec();
        switch (vec1[0]->pos_edge[0])
        {
        case 0:
        {
            bool B = D3->convey_sig(sig1,sig2);
            {

                if(B)
                {
                    //qDebug()<<B;
                    if(sig1 == sig2)
                    {
                        QMessageBox::information(this, "Error", "无法在同一点建立边");
                        return;
                    }
                    int **P = vec1[0]->return_p();
                    if( P[sig1-1][sig2-1] == 0)
                    {
                        P[sig1-1][sig2-1] = 1;
                        P[sig2-1][sig1-1] = 1;
                        vec1[0]->EdgeNum++;
                        update();
                    }
                    else
                    {
                          QMessageBox::information(this, "Error", "无法重复添加存在的边!");
                    }
                }
            }
            break;
        }
        case 1:
        {
            bool B = D3->convey_sig(sig1,sig2);
            {

                if(B)
                {
                    if(sig1 == sig2)
                    {
                        QMessageBox::information(this, "Error", "无法在同一点建立边");
                        return;
                    }
                    int **P = vec1[0]->return_p();
                    if( P[sig1-1][sig2-1] == 0)
                    {
                        P[sig1-1][sig2-1] = 1;
                        vec1[0]->EdgeNum++;
                        update();
                    }
                    else
                    {
                          QMessageBox::information(this, "Error", "无法重复添加存在的边!");
                    }
                }
            }
            break;
        }
        default:
            break;
        }
    }
    else
    {
        if(vec2[0]->DVertexNum < 2)
        {
            QMessageBox::information(this, "Error", "顶点数小于2\n无法建立边!!");
            return;
        }
        D3 = new DialogAddEdge(this);
        D3->get_range(1,vec2[0]->DVertexNum);
        D3->setModal(true);
        D3->exec();
            bool B = D3->convey_sig(sig1,sig2);
            {
                if(B)
                {
                    //qDebug()<<B;
                    if(sig1 == sig2)
                    {
                        QMessageBox::information(this, "Error", "无法在同一点建立边");
                        return;
                    }
                    int bb = vec2[0]->add_DEdge(sig1,sig2);
                    if(bb)
                    {
                        update();
                    }
                    else
                    {
                          QMessageBox::information(this, "Error", "无法重复添加存在的边!");
                    }
                }
            }
    }
}

void MainWindow::on_deletedge_triggered()
{
    if(vec1.size() == 0 && vec2.size() == 0)
    {
        QMessageBox::information(this, "Error", "未新建文件!!");
        return;
    }
    if(vec1.size() !=0)
    {
        if(vec1[0]->VertexNum < 2)
        {
            QMessageBox::information(this, "Error", "顶点数小于2\n何谈删边!!");
            return;
        }
        D4 = new DialogDeleteEdge(this);
        D4->get_range(1,vec1[0]->VertexNum);
        D4->setModal(true);
        D4->exec();
        int sig1,sig2;
        switch (vec1[0]->pos_edge[0])
        {
        case 0:
        {
            bool B = D4->convey_sig(sig1,sig2);
            {

                if(B)
                {
                    if(sig1 == sig2)
                    {
                        QMessageBox::information(this, "Error", "同一点无边");
                        return;
                    }
                    int **P = vec1[0]->return_p();
                    if(P[sig1-1][sig2-1])
                    {
                        P[sig1-1][sig2-1] = 0;
                        P[sig2-1][sig1-1] = 0;
                        vec1[0]->EdgeNum--;
                        update();
                    }
                    else
                    {
                       QMessageBox::information(this, "Error", "无法删除不存在的边!");
                    }

                }
            }
            break;
        }
        case 1:
        {
            bool B = D4->convey_sig(sig1,sig2);
            {
                if(sig1 == sig2)
                {
                    QMessageBox::information(this, "Error", "同一点无边");
                    return;
                }
                if(B)
                {
                    int **P = vec1[0]->return_p();
                    if(P[sig1-1][sig2-1])
                    {
                        P[sig1-1][sig2-1] = 0;
                        vec1[0]->EdgeNum--;
                        update();
                    }
                    else
                    {
                       QMessageBox::information(this, "Error", "无法删除不存在的边!");
                    }

                }
            }
            break;
        }
        default:
            break;
        }
    }
    else
    {
        if(vec2[0]->DVertexNum < 2)
        {
            QMessageBox::information(this, "Error", "顶点数小于2\n何谈删边!!");
            return;
        }
        D4 = new DialogDeleteEdge(this);
        D4->get_range(1,vec2[0]->DVertexNum);
        D4->setModal(true);
        D4->exec();
        int sig1,sig2;
        bool B = D4->convey_sig(sig1,sig2);
        {
            if(B)
            {
                if(sig1 == sig2)
                {
                    QMessageBox::information(this, "Error", "同一点无边");
                    return;
                }
                int bb = vec2[0]->delete_DEdge(sig1,sig2);
                if(bb)
                {
                    update();
                }
                else
                {
                      QMessageBox::information(this, "Error", "无法删除不存在的边!");
                }
            }
        }
    }
}

void MainWindow::on_newFile2_triggered()
{
    if(vec2.size()!=0 || vec1.size()!=0)
    {
        QMessageBox::information(this, "Error", "只能对一个文件进行操作");
        return;
    }
    D1 = new Dialog1(this);
    D1->setModal(true);
    D1->exec();
    string s;
    int t1=0;
    int t2=0;
    bool B = D1->getData(s,t1,t2);
    if(B)
    {
        if(s.size() == 0)
        {
            QMessageBox::information(this,"Error","未输入文件名");
            return;
        }
        graph2* g=new graph2(s,t1,t2);
        ui->label->setText("正在编辑图");
        ui->label_3->setText(("文件名:"+s).data());
        ui->label_4->setText("属性1:动态存储图");
        QString s1 = QString("属性2:");
        if(t1 == 0)
        {
            s1 = s1 + "无向图";
        }
        else
        {
            s1 += "有向图";
        }
        QString s2 = "属性3:";
        if(t2 == 0)
        {
            s2 += "无权图";
        }
        else
        {
            s2 += "加权图";
        }
        ui->label_5->setText(s1);
        ui->label_6->setText(s2);
        ui->label->show();
        ui->label_2->show();
        ui->label_3->show();
        ui->label_4->show();
        ui->label_5->show();
        ui->label_6->show();
        vec2.push_back(g);
    }
}


void MainWindow::on_saveFile_triggered()
{
    if(vec1.size() == 0 && vec2.size() == 0)
    {
        QMessageBox::information(this,"Error","未打开文件");
        return;
    }
    QString path = QFileDialog::getSaveFileName(this, "save", "../", "TXT(*.Qtxt)");
        if(path.isEmpty() == false)
        {
            QFile file; //创建文件对象
            //关联文件名字
            file.setFileName(path);

            //打开文件，只写方式
            bool isOk = file.open(QIODevice::WriteOnly);
            if(isOk == true)
            {
                QTextStream stream(&file);
                //指定编码
                stream.setCodec("UTF-8");
                if(vec1.size() != 0)
                {
                    stream << QString("static\n");
                    stream<< vec1[0]->VertexNum<<" "<<vec1[0]->EdgeNum<<"\n";
                    stream <<vec1[0]->pos_edge[0]<<" "<<vec1[0]->pos_edge[1]<<"\n";
                    int **P = vec1[0]->return_p();
                    for(int i=0; i < vec1[0]->VertexNum; i++)
                    {
                       stream <<vec1[0]->vecbutton[i]->x()<<" "<<vec1[0]->vecbutton[i]->y()<<"\n";
                    }
                    stream<<"-1\n";

                    for(int i=0; i < vec1[0]->VertexNum; i++)
                        {
                            for(int j=0; j < vec1[0]->VertexNum; j++)
                            stream<<P[i][j]<<" ";
                           stream<<"\n";
                        }
                    vec1.pop_back();
                    int asd = vec1[0]->vecbutton.size();
                    QPushButton *pb;
                    for(int i=asd-1; i>=0; i--)
                    {
                        vec1[0]->vecbutton[i]->hide();
                        pb = vec1[0]->vecbutton[i];
                        vec1[0]->vecbutton.pop_back();
                        delete pb;
                    }

                }
                else
                {
                    stream <<QString("dynamic\n");
                    stream<< vec2[0]->DVertexNum<<" "<<vec2[0]->DEdgeNum<<"\n";
                    stream <<vec2[0]->Dpos_edge[0]<<" "<<vec2[0]->Dpos_edge[1]<<"\n";
                    for(int i=0; i < vec2[0]->DVertexNum; i++)
                    {
                       stream <<vec2[0]->vecbutton[i]->x()<<" "<<vec2[0]->vecbutton[i]->y()<<"\n";
                    }
                    stream<<"-1\n";

                    for(int i=0; i < vec2[0]->DVertexNum; i++)
                    {
                      stream<<i+1<<" ";
                      node *pp = vec2[0]->Dvect[i].pnext->next;
                      while(pp!=NULL)
                      {
                          stream << pp->adjvex << " " << pp->weight<<" ";
                          pp=pp->next;
                      }
                      stream <<"-666\n";
                    }
                    vec2.pop_back();
                    int asd = vec2[0]->vecbutton.size();
                    QPushButton *pb;
                    for(int i=asd-1; i>=0; i--)
                    {
                        vec2[0]->vecbutton[i]->hide();
                        pb = vec2[0]->vecbutton[i];
                        vec2[0]->vecbutton.pop_back();
                        delete pb;
                    }
                    vec2[0]->vecbutton.clear();
                }
                update();
                ui->label->setText("未打开文件");
                ui->label_2->hide();
                ui->label_3->hide();
                ui->label_4->hide();
                ui->label_5->hide();
                ui->label_6->hide();
            }

            file.flush();
            file.close();
        }
}

void MainWindow::on_openFile_triggered()
{
    if(vec2.size()!=0 || vec1.size()!=0)
    {
        if(QMessageBox::question(this,"提示","是否保存当前文件?") == QMessageBox::Yes)
        {
            on_save2File_triggered();
        }
        else
        {
            if(vec1.size() !=0 )
            {
                vec1.pop_back();
                int asd = vec1[0]->vecbutton.size();
                QPushButton *pb;
                for(int i=asd-1; i>=0; i--)
                {
                    vec1[0]->vecbutton[i]->hide();
                    pb = vec1[0]->vecbutton[i];
                    vec1[0]->vecbutton.pop_back();
                    delete pb;
                }
            }
            else
            {
                vec2.pop_back();
                int asd = vec2[0]->vecbutton.size();
                QPushButton *pb;
                for(int i=asd-1; i>=0; i--)
                {
                    vec2[0]->vecbutton[i]->hide();
                    pb = vec2[0]->vecbutton[i];
                    vec2[0]->vecbutton.pop_back();
                    delete pb;
                }
                vec2[0]->vecbutton.clear();
            }
            ui->label->setText("未打开文件");
            ui->label_2->hide();
            ui->label_3->hide();
            ui->label_4->hide();
            ui->label_5->hide();
            ui->label_6->hide();
            update();
        }
        //on_openFile_triggered();
        return;
    }
    QString path = QFileDialog::getOpenFileName(this, "open", "../", "TXT(*.Qtxt)");
        if(path.isEmpty() == false)
        {
            QFileInfo file1(path); //创建文件对象
            //关联文件名字
            QString filnam = file1.fileName();
            //file1.close();

            QFile file;
            file.setFileName(path);

            //打开文件，只读方式
            bool isOk = file.open(QIODevice::ReadOnly);

            if(isOk == true)
            {
                QTextStream stream(&file);
                //指定编码
                stream.setCodec("UTF-8");
                QString graphType;
                stream >> graphType;
                if( graphType == "static")
                {
                    ui->label_2->setText("静态存储图");
                    int a,b,c,d;
                    graph1 *g = new graph1;
                    vec1.push_back(g);
                    stream >> a >> b >> c >>d;
                    g->graph(path.toStdString(),a,b,c,d);
                    int aa,bb;
                    QPoint ppoint;
                    while(1)
                    {
                        stream>>aa;
                        if(aa == -1) break;
                        stream>>bb;
                        ppoint.setX(aa);
                        ppoint.setY(bb);
                        pbutton = new QPushButton;
                        pbutton->setParent(this);
                        pbutton->resize(30,30);
                        pbutton->move(ppoint);
                        pbutton->setStyleSheet("background-color: rgb(116, 215, 47);");
                        vec1[0]->vecbutton.push_back(pbutton);
                    }
                    showButton();
                    int ** P = g->return_p();
                    for(int i=0; i<g->VertexNum; i++)
                    {
                        for(int j=0; j<g->VertexNum; j++)
                        {
                            stream >> P[i][j];
                        }
                    }
                    ui->label->setText("正在编辑图");
                    ui->label_3->setText("文件名:"+filnam);
                    ui->label_4->setText("属性1:静态存储图");
                    QString s1 = QString("属性2:");
                    if(c == 0)
                    {
                        s1 = s1 + "无向图";
                    }
                    else
                    {
                        s1 += "有向图";
                    }
                    QString s2 = "属性3:";
                    if(d == 0)
                    {
                        s2 += "无权图";
                    }
                    else
                    {
                        s2 += "加权图";
                    }
                    ui->label_5->setText(s1);
                    ui->label_6->setText(s2);
                    ui->label->show();
                    ui->label_2->show();
                    ui->label_3->show();
                    ui->label_4->show();
                    ui->label_5->show();
                    ui->label_6->show();
                }
                if(graphType == "dynamic")
                {
                    int a,b,c,d;
                    graph2 *g = new graph2;
                    vec2.push_back(g);
                    stream >> a >> b >> c >>d;
                    g->graph22(path.toStdString(),0,0,c,d);
                    int aa,bb;
                    QPoint ppoint;
                    while(1)
                    {
                        stream>>aa;
                        if(aa == -1) break;
                        stream>>bb;
                        ppoint.setX(aa);
                        ppoint.setY(bb);
                        pbutton = new QPushButton;
                        pbutton->setParent(this);
                        pbutton->resize(30,30);
                        pbutton->setStyleSheet("background-color: rgb(116, 215, 47);");
                        pbutton->move(ppoint);
                        vec2[0]->vecbutton.push_back(pbutton);
                    }
                    showButton();
                    int mm;
                    for(int i=0; i<a; i++)
                    {
                        g->add_DVertex();
                    }

                    int nn;
                    for(int i=0; i<a; i++)
                    {
                        stream >> mm;
                        while(1)
                        {
                            stream>>mm;
                            if(mm == -666) break;
                            stream>>nn;
                            g->add_DEdge(i+1,mm);
                        }
                    }
                    ui->label->setText("正在编辑图");
                    ui->label_3->setText("文件名:"+filnam);
                    ui->label_4->setText("属性1:动态存储图");
                    QString s1 = QString("属性2:");
                    if(c == 0)
                    {
                        s1 = s1 + "无向图";
                    }
                    else
                    {
                        s1 += "有向图";
                    }
                    QString s2 = "属性3:";
                    if(d == 0)
                    {
                        s2 += "无权图";
                    }
                    else
                    {
                        s2 += "加权图";
                    }
                    ui->label_5->setText(s1);
                    ui->label_6->setText(s2);
                    ui->label->show();
                    ui->label_2->show();
                    ui->label_3->show();
                    ui->label_4->show();
                    ui->label_5->show();
                    ui->label_6->show();
                }

                update();
            }
            file.flush();
            file.close();
        }
}

void MainWindow::on_save2File_triggered()
{
    if(vec1.size() == 0 && vec2.size() == 0)
    {
        QMessageBox::information(this,"Error","未打开文件");
        return;
    }
    string filnam;
    if(vec1.size() != 0)
    {
        filnam = vec1[0]->filename;
    }
    else
    {
        filnam = vec2[0]->Dfilename;
    }
            QFile *file = new QFile; //创建文件对象
            //关联文件名字
            file->setFileName( (QString::fromStdString(filnam)).toUtf8());

            //打开文件，只写方式
            bool isOk = file->open(QIODevice::WriteOnly);
            QTextStream stream(file);
            if(isOk == true)
            {
                //指定编码
                stream.setCodec("UTF-8");
                if(vec1.size() != 0)
                {
                    stream << QString("static\n");
                    stream<< vec1[0]->VertexNum<<" "<<vec1[0]->EdgeNum<<"\n";
                    stream <<vec1[0]->pos_edge[0]<<" "<<vec1[0]->pos_edge[1]<<"\n";
                    int **P = vec1[0]->return_p();
                    for(int i=0; i < vec1[0]->VertexNum; i++)
                    {
                       stream <<vec1[0]->vecbutton[i]->x()<<" "<<vec1[0]->vecbutton[i]->y()<<"\n";
                    }
                    stream<<"-1\n";

                    for(int i=0; i < vec1[0]->VertexNum; i++)
                        {
                            for(int j=0; j < vec1[0]->VertexNum; j++)
                            stream<<P[i][j]<<" ";
                           stream<<"\n";
                        }
                    vec1.pop_back();
                    int asd = vec1[0]->vecbutton.size();
                    QPushButton *pb;
                    for(int i=asd-1; i>=0; i--)
                    {
                        vec1[0]->vecbutton[i]->hide();
                        pb = vec1[0]->vecbutton[i];
                        vec1[0]->vecbutton.pop_back();
                        delete pb;
                    }
                    vec1[0]->vecbutton.clear();
                }
                else
                {
                    stream <<QString("dynamic\n");
                    stream<< vec2[0]->DVertexNum<<" "<<vec2[0]->DEdgeNum<<"\n";
                    stream <<vec2[0]->Dpos_edge[0]<<" "<<vec2[0]->Dpos_edge[1]<<"\n";
                    for(int i=0; i < vec2[0]->DVertexNum; i++)
                    {
                       stream <<vec2[0]->vecbutton[i]->x()<<" "<<vec2[0]->vecbutton[i]->y()<<"\n";
                    }
                    stream<<"-1\n";

                    for(int i=0; i < vec2[0]->DVertexNum; i++)
                    {
                      stream<<i+1<<" ";
                      node *pp = vec2[0]->Dvect[i].pnext->next;
                      while(pp!=NULL)
                      {
                          stream << pp->adjvex << " " << pp->weight<<" ";
                          pp=pp->next;
                      }
                      stream <<"-666\n";
                    }
                    vec2.pop_back();
                    int asd = vec2[0]->vecbutton.size();
                    QPushButton *pb;
                    for(int i=asd-1; i>=0; i--)
                    {
                        vec2[0]->vecbutton[i]->hide();
                        pb = vec2[0]->vecbutton[i];
                        vec2[0]->vecbutton.pop_back();
                        delete pb;
                    }
                    vec2[0]->vecbutton.clear();
                }

                ui->label->setText("未打开文件");
                ui->label_2->hide();
                ui->label_3->hide();
                ui->label_4->hide();
                ui->label_5->hide();
                ui->label_6->hide();
            }
            else
                on_saveFile_triggered();
            update();

            file->flush();
            file->close();
            delete file;

}

void MainWindow::on_aboutAction_triggered()
{
    Help *DD = new Help(this);
    DD->setModal(false);
    DD->show();
}
