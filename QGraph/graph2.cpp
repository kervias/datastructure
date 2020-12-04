#include "graph2.h"

graph2::graph2()
{
    DVertexNum = 0;
    DEdgeNum = 0;
}

void graph2::graph22(string s,int a,int b, int c, int d)
{
    Dfilename = s;
    DVertexNum = a;
    DEdgeNum = b;
    Dpos_edge[0] = a;
    Dpos_edge[1] = b;

}

void graph2::delete_nc(node *p)
{
    if(p->next != NULL)
    {
        delete_nc(p->next);
    }
    delete p;
}

graph2::~graph2()
{
    for(int i=0; i<Dvect.size(); i++)
    {
        if(Dvect[i].pnext!=NULL)
        {
            delete_nc(Dvect[i].pnext);
        }
    }
    Dvect.clear();
}



void graph2::add_DVertex()
{
    DVertexNum++;
    Vertex2 v;
    v.pnext = new node;
    v.pnext->next = NULL;
    v.last =v.pnext;
    Dvect.push_back(v);
    //qDebug()<<"顶点添加成功";
}

void graph2::delete_DVertex(int n)
{
    DVertexNum--;
    node *p,*temp;
    int t = 0;
    for(int i=0; i<Dvect.size(); i++)
    {
        p = Dvect[i].pnext->next;
        temp = Dvect[i].pnext;
        t =0 ;
         qDebug()<<"******************";
       while(p != NULL)
       {
           if(p->adjvex == n)
           {
               temp->next = p->next;
               if(p == Dvect[i].last)
               {
                   Dvect[i].last = temp;
               }
               t = 1;
           }
           if(p->adjvex > n)
           {
               p->adjvex--;
           }
           p = p->next;
       }

       if(t == 1)
       {
           delete p;
       }
    }
   delete_nc(Dvect[n-1].pnext);
    Dvect.erase(Dvect.begin()+n-1);
}

bool graph2::add_DEdge(int n1,int n2)
{
    node *pp,*temp;
    if(Dpos_edge[0] == 0)
    {
        pp = Dvect[n1-1].pnext->next;
        while(pp!=NULL)
       {
           if(pp->adjvex == n2)
           {
              break;
           }
           pp =pp->next;
        }
        if(pp != NULL) return 0;
        else
        {
            pp = Dvect[n2-1].pnext->next;
            while(pp!=NULL)
            {
                if(pp->adjvex == n1)
                {
                    break;
                }
                pp = pp->next;
            }
            if(pp!=NULL) return 0;
            else
            {
                node *pq = new node;
                pq->adjvex = n2;
                pq->weight = 0;
                pq->next= NULL;
                Dvect[n1-1].last->next = pq;
                Dvect[n1-1].last = pq;
                DEdgeNum++;
                return 1;
            }
        }

    }
    else
    {
        pp = Dvect[n1-1].pnext->next;
        while(pp!=NULL)
       {
           if(pp->adjvex == n2)
           {
              break;
           }
           pp = pp->next;
        }
        if(pp != NULL) return 0;
        else
        {
            pp = new node;
            pp->adjvex = n2;
            pp->weight = 0;
            pp->next= NULL;
            Dvect[n1-1].last->next = pp;
            Dvect[n1-1].last = pp;
             DEdgeNum++;
            return 1;
        }
    }

}

bool graph2::delete_DEdge(int n1,int n2)
{
    node *pp;
    node *temp;
    if(Dpos_edge[0] == 0)
    {
        pp = Dvect[n1-1].pnext->next;
        temp = Dvect[n1-1].pnext;
        while(pp != NULL)
        {
            if(pp->adjvex == n2)
            {
                temp->next = pp->next;
                if(Dvect[n1-1].last == pp)
                {
                    Dvect[n1-1].last = temp;
                }
                DEdgeNum--;
                break;
            }
            temp = pp;
            pp = pp->next;
        }
        if(pp != NULL)
        {
            delete pp;
            return 1;
        }
        else
        {
            pp = Dvect[n2-1].pnext;
            temp = NULL;
            while(pp != NULL)
            {
                if(pp->adjvex == n1)
                {
                    temp->next = pp->next;
                    if(Dvect[n2-1].last == pp)
                    {
                        Dvect[n2-1].last = temp;
                    }
                   DEdgeNum--;
                   break;
                }
                temp = pp;
                pp = pp->next;
            }
            if(pp == NULL) return 0;
            else
            {
                delete pp;
                return 1;
            }
        }
    }
    else
    {
        pp = Dvect[n1-1].pnext;
        temp = NULL;
        while(pp != NULL)
        {
            if(pp->adjvex == n2)
            {
                temp->next = pp->next;
                if(Dvect[n2-1].last == pp)
                {
                    Dvect[n2-1].last = temp;
                }
                DEdgeNum--;
                break;
            }
            temp = pp;
            pp = pp->next;
        }
        if(pp != NULL)
        {
            delete pp;
            return 1;
        }
        else
        return 0;
    }

}

graph2::graph2(string s, int n1, int n2)
{
    Dfilename = s;
    DVertexNum = 0;
    DEdgeNum = 0;
    Dpos_edge[0] = n1;
    Dpos_edge[1] = n2;
}
