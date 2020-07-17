#include <bits/stdc++.h>
#define MAXN 100010
#define MAXM 200010
using namespace std;
int rd[MAXN],vis[MAXN],head[MAXN],ans[MAXN],temp[MAXN],cont,n,m;
struct node{
int v,next;}edge[MAXM];

queue <int> q;

int cnt=0;
void build(int u,int v)
{cnt++; edge[cnt].v=v; edge[cnt].next=head[u]; head[u]=cnt;}

int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int xx,yy; cin>>xx>>yy; build(xx,yy);
        rd[yy]++;
    }
    
    for (int i=1;i<=n;i++)
        if (!rd[i]) q.push(i);

    while (!q.empty())
    {
        int tmp2=q.front(); q.pop();
        for (int i=head[tmp2];i;i=edge[i].next)
        {
            rd[edge[i].v]--; ans[edge[i].v]=max(ans[edge[i].v],ans[tmp2]+1);
            if (rd[edge[i].v]==0) {q.push(edge[i].v);}
        }

    }
    for (int i=1;i<=n;i++) cout<<ans[i]+1<<endl;
    return 0;
}
/* 我cyq的算法为什么只值60分？
    汗汗汗
    whyyy？
    利用贪心思想，在按照拓扑排序的顺序，（也不是拓扑排序），直接找入度为0的点。全部压入队伍。<-initialize
    对于每个点，如果已经被更新过了，就再找一编判断一下（其实这里可以存一个“被影响的链”然后把那条链上的数值全部加1；
                如果没有被更新过，则找一下看看。
                如果找过了却没有被更新，那就找啊？
            按照入度为第一关键字升序排序，ans(也就是能够找到的点降序排序)

    果然要queue来搞。

*/