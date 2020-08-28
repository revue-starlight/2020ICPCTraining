#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int M = 2e5+10;
struct add{
    int next,v;
}edge[M];
int head[N];
int tot=0;
inline void add(int x,int y){
    edge[++tot].v=y; edge[tot].next=head[x]; head[x]=tot;
}
int dis[N>>1];
int mode[N>>1];
int main(){
    int T;
    cin>>T;
    int n,m,timee,s,t;
    while (T--){
        cin>>n>>m>>s>>t>>timee;
        string s;
        cin>>s;
        memset(mode,0,sizeof(mode));
        for (int i=0;i<n;i++) {
            if (s[i]=='L') mode[i+1]=1;
            if (s[i]=='R') mode[i+1+n]=1;
            if (s[i]=='M') mode[i+1]=1,mode[i+1+n]=1;
        }
        for (int i=1;i<=m;i++){
            int x,y,w;
            cin>>x>>y>>w;
            if (mode[x] && mode[y+n]) add(x,y+n,timee+w),add(y+n,x,timee+w);
            if (mode[x+n] && mode[y]) add(y,x+n,timee+w),add(x+n,y,timee+w);
            if (mode[x+n] && mode[y+n]) add(x+n,y+n,w),add(x+n,y+n,w);
            if (mode[x] && mode[y]) add(x,y,w),add(y,x,w);
        }


    }
}