#ifndef GRAPH2_H
#define GRAPH2_H
#include <iostream>
#include <vector>
#include <QDebug>
#include <QPushButton>
using namespace std;
struct node
{
    int adjvex;   //顶点下标
    int weight;   //权值
    node *next;
};

struct Vertex2    //顶点
{
    vector<string> Dvec;
    node *pnext;
    node *last;
};

class graph2   //动态存储图
{
    public:
    graph2();
    graph2(string s, int n1,int n2);
    void graph22(string s,int a,int b, int c, int d);
    ~graph2();
    void add_DVertex();
    void delete_DVertex(int n);
    bool add_DEdge(int n1,int n2);
    bool delete_DEdge(int n1,int n2);
    void delete_nc(node *p);  //删除内存
    //private:
    vector<Vertex2> Dvect;
    int DVertexNum;   //顶点数目
    int DEdgeNum;  //边的数目
    string Dfilename;  //文件名(dynamic-)
    int Dpos_edge[2];
    vector<QPushButton*> vecbutton;
};
#endif // GRAPH2_H
