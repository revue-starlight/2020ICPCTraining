#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 1001
#define MAXM 500000
int bcj[MAXN];

int find(int x)
{
    while (x!=bcj[x]) x=bcj[x]=bcj[bcj[x]];
    return x;
}

struct node{
    int u,v; double w;
    bool operator< (const node &b) const{return w<b.w;}
}edge[MAXM];
struct node2{
    int x,y;
}point[MAXN];

int cnt=0;
double dis[MAXN][MAXN];

double work_dis(int i,int j)
{
    return sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y));
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
      scanf("%d%d",&point[i].x,&point[i].y);
    for (int i=1;i<=n;i++)
      for (int j=1;j<i;j++)
      {
          dis[i][j]=work_dis(i,j);
          dis[j][i]=dis[i][j];
      }
    int m;
    scanf("%d",&m);
    
    for (int i=1;i<=n;i++) bcj[i]=i; 
    for (int i=1;i<=m;i++)
    {int xx,yy; scanf("%d%d",&xx,&yy); dis[xx][yy]=0; dis[yy][xx]=0; bcj[find(xx)]=find(yy);}

    int cnt=0;
    for (int i=1;i<=n;i++)
     for (int j=1;j<i;j++)
    {
        cnt++;
        edge[cnt].u=i; edge[cnt].v=j; edge[cnt].w=dis[i][j];
    }
    sort(edge+1,edge+1+cnt);
    cnt=0;
    int sum; bool vo=false;
    for (int i=1;i<=cnt;i++)
     {
        int eu=find(edge[i].u);int ev=find(edge[i].v);
        if (eu==ev) continue;
        vo=true;
        bcj[eu]=ev;
        cout<<edge[i].u<<" "<<edge[i].v<<endl;
     }
     if (!vo) cout<<" ";
}