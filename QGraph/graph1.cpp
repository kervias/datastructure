#include "graph1.h"

graph1::graph1()
{
     p = NULL;
     VertexNum = 0;
     EdgeNum = 0;
     pos_edge[0] = 0;
     pos_edge[1] = 0;
}
 void graph1::graph(string s,int n,int m,int n1,int n2)
 {
     VertexNum = n;
     p = new int*[VertexNum];
     for(int i=0; i<VertexNum; i++)
     p[i] = new int[VertexNum];

     for(int i=0; i<VertexNum; i++)
     {
         for(int j=0; j<VertexNum; j++)
        p[i][j] =0;
     }
     EdgeNum = 0;
     filename = s;
     pos_edge[0] = n1;
     pos_edge[1] = n2;
 }

graph1::graph1(string s,int n1,int n2)
{
    VertexNum = 0;
    EdgeNum = 0;
    filename = s;
    pos_edge[0] = n1;
    pos_edge[1] = n2;
}

void graph1::add_vertex()  //增加一个顶点
{
    //vect.push_back(temp);
    int **p1;
    if(VertexNum > 0)
    {
        p1 = new int*[VertexNum];  //生成辅助空间用来存储
        for(int i=0; i<VertexNum; i++)
        {
            p1[i] = new int[VertexNum];
        }

        for(int i=0; i<VertexNum; i++)    //将原先二维数组的值赋给辅助空间
        {
            for(int j=0; j<VertexNum; j++)
            p1[i][j] = p[i][j];
        }

        for(int i = 0; i < VertexNum; i++)  //释放原先申请的内存
        delete[] p[i];
        delete[] p;
    }
    VertexNum ++;

    p = new int*[VertexNum];          //重新生成空间
    for(int i=0; i<VertexNum; i++)
    p[i] = new int[VertexNum];

    for(int i=0; i<VertexNum-1; i++)
    {
        for(int j=0; j<VertexNum-1; j++)
        p[i][j] = p1[i][j];
    }

    for(int i=0; i<VertexNum; i++)  //新顶点关系初始化为0
    {
        p[i][VertexNum-1] = 0;
        p[VertexNum-1][i] = 0;
    }

    for(int i = 0; i < VertexNum-1; i++)  //释放辅助空间
        delete[] p1[i];
        delete[] p1;
}

bool graph1::delete_vertex(int loc)  //删除指定结点
{
    if(VertexNum == 0 || loc >VertexNum)
    return 0;
    //vect.erase(vect.begin()+loc-1);

    int **p1 = new int*[VertexNum];  //生成辅助空间用来存储
    for(int i=0; i<VertexNum; i++)
    {
         p1[i] = new int[VertexNum];
    }
    for(int i=0; i<VertexNum; i++)    //将原先二维数组的值赋给辅助空间
    {
         for(int j=0; j<VertexNum; j++)
         {
            p1[i][j] = p[i][j];
        }

    }
    for(int i = 0; i < VertexNum; i++)  //释放原先申请的内存
    delete[] p[i];
    delete[] p;

    VertexNum --;
    int a,b;
    p = new int*[VertexNum];          //重新生成空间
    for(int i=0; i<VertexNum; i++)
    p[i] = new int[VertexNum];

    for(int i=0; i<VertexNum; i++)
    {
        for(int j=0; j<VertexNum; j++)
        {
            a = i;
            b= j;
            if(a >= loc-1) a++;
            if(b >= loc-1) b++;
            p[i][j] = p1[a][b];
        }
    }
    for(int i = 0; i < VertexNum+1; i++)  //释放辅助空间
        delete[] p1[i];
        delete[] p1;
    return 1;
}

vertex1 graph1::seek1(int n1)   //查找结点,返回结点信息(需要判断n1界限)
{
    vertex1 temp;
    temp = vect[n1-1];
    return temp;
}

int graph1::seek2(int n1,int n2)  //查找权数,需要判断n1和n2界限
{
    return p[n1-1][n2-1];
}

int **graph1::return_p()  //返回二维数组
{
    return p;
}

int graph1::return_VertexNum() //返回顶点数目
{
    return VertexNum;
}

int graph1::return_EdgeNum() //返回边的数目
{
    return EdgeNum;
}

vector<vertex1> graph1::return_vect()  //返回顶点集
{
    return vect;
}

bool graph1::change_Vertex1(int loc, int m, string s)   //更改顶点信息
{
    if(loc <=0 || loc >VertexNum) return 0;
    vect[loc-1].vec[m-1] = s;
    return 1;
}

void graph1::set_Edge(int n1,int n2,int num)  //设定权数
{
    if(p[n1-1][n2-1] == 0 && num!=0) EdgeNum++;
    if(p[n1-1][n2-1] != 0 && num == 0) EdgeNum--;
    p[n1-1][n2-1] = num;
}

void graph1::add_vertex_info(int loc, string s)   //添加结点信息
{
    vect[loc-1].vec.push_back(s);
}

void graph1::delete_vertex_info(int loc, string s)  //删除结点信息
{
    vect[loc-1].vec.pop_back();
}
