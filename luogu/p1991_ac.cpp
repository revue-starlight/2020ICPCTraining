//using kruskal to solve this
//gotta use greedy and dsu
#include <bits/stdc++.h>
using namespace std;
int s,p,dsu[501];
double forsort[501];

struct node{
    int x,y;
}nodes[501];

struct edges{
    int u,v;
    double dis;
    bool operator < (const edges& b) const
        {return dis>b.dis;}
}edge[501*501];
priority_queue <edges> q;

    int find(int x){
        if(x!=dsu[x])dsu[x]=find(dsu[x]);
        return dsu[x];
    }
    inline void joint(int x,int y)  {  
        dsu[find(x)]=find(y);  
    }

int main()
{
    cin>>s>>p; int cnt=0;
    for (int i=1;i<=p;i++)
    {
        int x,y; cin>>x>>y; nodes[i].x=x; nodes[i].y=y;
        for (int j=1;j<i;j++)
        {
            cnt++;
            edge[cnt].u=i; edge[cnt].v=j; edge[cnt].dis=sqrt((nodes[j].x-x)*(nodes[j].x-x)+(nodes[j].y-y)*(nodes[j].y-y));
            q.push(edge[cnt]);
        }
    }
    int t=1;
    for (int i=1;i<=p;i++) dsu[i]=i; //initialize the dsu
    while (t<p)
    {
        edges tmp; tmp=q.top(); q.pop();
        if (find(tmp.u)==find(tmp.v)) continue;
        else {joint(tmp.u,tmp.v); forsort[t]=tmp.dis; t++;}
    }
    sort(forsort+1,forsort+p);
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<forsort[p-s]<<endl;
    return 0;
}
