#include <iostream>
#include <stack>
#define maxn 201
using namespace std;
struct node{
    int u,v,next;
}edge[maxn];
int value[maxn],head[maxn],cnt;
stack <int> tarjan_vec;


inline void build(int u,int v){
    cnt++; edge[cnt].u=u; edge[cnt].v=v; edge[cnt].next=head[u]; head[u]=cnt;
}

bool visited[maxn];
int tarjan_time[maxn],tarjan_low[maxn],clock;

inline void tarjan(int x){
    clock++; visited[x]=1; tarjan_stack.push(x);
    tarjan_time[x]=tarjan_low[x]=clock;
    for (int i=head[x];i;i=edge[i].next){
        if (!visited[edge[i].v]) tarjan(edge[i].v);
        if (tarjan_low[edge[i].v]<=tarjan_low[x]) tarjan_low[x]=tarjan_low[edge[i].v];
    }
    if (tarjan_low[x]==tarjan_time[x]) {
        while (tarjan_stack.top()!=x)
    }
}
int main(){
    int n,m;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",value+i);
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        build(u,v);
    }
    
    for (int i=1;i<=n;i++){
        tarjan(i);
    }
}