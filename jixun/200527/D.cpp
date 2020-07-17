#include <bits/stdc++.h>
using namespace std;
#define maxn 100004
int a[maxn];
int n,k;
int ans[maxn];
bool bo[maxn];
inline int find(int x){
    if (a[x]==x) return x; else return a[x]=find(a[x]);
}
inline void dsu (int x,int y){
    int xx=find(x),yy=find(y);
    if (xx!=yy)
    {a[xx]=yy,ans[yy]=ans[yy]+ans[xx];}
}

int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++) ans[i]=1;
    for (int i=1;i<=n;i++) a[i]=i;
    for (int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        dsu(x,y);
    }
    int output=0;
    for (int i=1;i<=n;i++){
        if (a[i]==i) {output=output+ans[i]-1;}
    }
    cout<<k-output<<endl;

    
}