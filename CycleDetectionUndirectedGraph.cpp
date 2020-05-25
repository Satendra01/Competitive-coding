#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int nodeA,nodeB;
};
class Graph{
    public:
    int V,E;
    Edge *e;
};
Graph* createGraph(int V,int E)
{
    Graph* g=new Graph();
    g->V=V;g->E=E;
    g->e=new Edge[E*sizeof(Edge)];
    return g;
}
int find(int node,int *parent)
{
    while(parent[node]!=-1)
    node=parent[node];
    return node;
}
void Union(int *parent,int A,int B)
{
    int Aset=find(A,parent);
    int Bset=find(B,parent);
    parent[Bset]=Aset;
}
bool isCyclic(Graph *g)
{
   int *parent=new int[g->V*sizeof(int)];
   memset(parent,-1,sizeof(int)*g->V);
   for(int i=0;i<g->E;i++)
   {
       int a=find(g->e[i].nodeA,parent);
       int b=find(g->e[i].nodeB,parent);
       if(a==b)
       return true;
       Union(parent,a,b);
   } 
   return false;
}
int main()
{
    int V,E;
    V=3;E=2;
    Graph *g=createGraph(V,E);
    g->e[0].nodeA=1;
    g->e[0].nodeB=2;
    g->e[1].nodeA=2;
    g->e[1].nodeB=1;
    // cout<<"graph is"<<endl;
    // for (int i=0;i<E;i++)
    // {
    //     cout<<g->e[i].nodeA<<"->"<<g->e[i].nodeB<<endl;
    // }
    bool val=isCyclic(g);
    cout<<val;
    return 0;
}