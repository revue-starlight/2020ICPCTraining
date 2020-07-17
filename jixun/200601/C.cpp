#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 2000
struct node{
    int next,val,u,v;
}edge[maxn];
int cnt=0;
int head[maxn];
inline void build(int u,int v){
    edge[cnt].u=u; edge[cnt].v=v; edge[cnt].val=0; edge[cnt].next=head[u]; head[u]=cnt; cnt++;
}

int dfs(int x,int fa){
    int ret=1;
    for (int k=head[x];k;k=edge[k].next){
        if (edge[k].v==fa) continue;
            ret=ret+dfs(edge[k].v,x);
    }
    return ret;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        memset(head,0,sizeof(head));

        int n,x;
        cin>>n>>x;
        for (int i=1;i<n;i++){
            int uu,vv; cin>>uu>>vv; build(uu,vv); build(vv,uu);
        }
        int ans[3]={0,0,0};
        int po=0;
        for (int xx=head[x];xx;xx=edge[xx].next){
            int e=edge[x].v;
            ans[po++]=dfs(e,x); 
        }
        
        sort(ans,ans+po);
        int anss=ans[0]+ans[1];
        if (po==1) {cout<<"Ashish"<<endl;}
        else if (po==2) {if (anss%2==0) cout<<"Ayush"<<endl; else cout<<"Ashish"<<endl;}
        else {if (anss%2==0) cout<<"Ashish"<<endl; else cout<<"Ayush"<<endl;}
    }
}