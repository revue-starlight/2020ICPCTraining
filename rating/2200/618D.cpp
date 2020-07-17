/*https://codeforces.com/problemset/problem/618/D*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200005
vector <int> vec[maxn];
int ans=0,n,x,y;
int dfs(int u,int p){
    int left=2;
    for (int i=0;i<vec[u].size();i++){
        int v=vec[u][i];
        if (v==p) continue;
        int x=dfs(v,u);
        if (left>0 && x==1) ans++,left--;
    }
    return left>0 ? 1:0;
}

int main(){
    cin>>n>>x>>y;
    int u,v;
    ll s1,s2;
    for (int i=0;i<n-1;i++){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    ans=0;
    if (x<y){
        dfs(1,-1);
        s1=(ll)ans*x+(ll)(n-ans-1)*y;
        cout<<s1<<endl;
    }
    else{
        for (int i=1;i<=n;i++){
            if ((int)vec[i].size()==n-1){ans=1; break;}
        }
        s2=(ll)ans*x+(ll)(n-ans-1)*y;
        cout<<s2<<endl;
    }
    return 0;
}