#ifndef GRAPH1_H
#define GRAPH1_H
#include <iostream>
#include <vector>
#include <QPushButton>
using namespace std;
struct vertex1
{
    vector<string> vec;  //存储结点信息
};


class graph1    //静态图类
{
    public:
    graph1();
    graph1(string s,int n1,int n2);
    void graph(string s,int n,int m,int n1,int n2);
    void add_vertex();   //增加一个顶点
    bool delete_vertex(int loc);   //删除一个顶点
    bool change_Vertex1(int loc, int m, string s);   //更改顶点信息
    void set_Edge(int n1,int n2,int num);  //设定权数
    void add_vertex_info(int loc, string s);   //添加结点信息
    void delete_vertex_info(int loc, string s);  //删除结点信息
    int **return_p();  //返回邻接矩阵,以一维数组的形式
    int return_VertexNum();  //返回顶点数目
    int return_EdgeNum(); //返回边的数目
    vector<vertex1> return_vect();  //返回顶点集
    vertex1 seek1(int n1);  //查找顶点,返回结点信息
    int seek2(int n1, int n2);  //查找边,返回权数
    //private:
    int **p;  //邻接矩阵
    int VertexNum;   //顶点数目
    int EdgeNum;  //边的数目
    vector<vertex1> vect;  //顶点集
    string filename;
    int pos_edge[2];
    vector<QPushButton*> vecbutton;
};

#endif // GRAPH1_H
