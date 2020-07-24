#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
ll n,k,T;
struct node{
    int a,b,c,d;
};

vector <node> tmpvec[51];
vector <node> vec[51];
ll ans=-1;

inline void dfs(ll typ,ll tmpa,ll tmpb,ll tmpc,ll tmpd){
    if (typ==k+1) {
        ll tmp=tmpa*tmpb*tmpc*tmpd;
        if (ans<tmp) 
            ans=tmp;
        return;
    }
    ll len=vec[typ].size();
    for (ll i=0;i<len;i++){
        dfs(typ+1,tmpa+vec[typ][i].a,tmpb+vec[typ][i].b,tmpc+vec[typ][i].c,tmpd+vec[typ][i].d);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while (T--){
        ans=-1;
        cin>>n>>k;
        for (int i=1;i<=50;++i) tmpvec[i].clear();
        for (int i=1;i<=n;++i){
            ll type; node tmp;
            cin>>type>>tmp.a>>tmp.b>>tmp.c>>tmp.d;
            tmpvec[type].push_back(tmp);
        }
        int p=0;
        for (int i=1;i<=k;++i){
            if (tmpvec[i].size()==0) continue;
            vec[++p]=tmpvec[i];
        }
    k=p;
    dfs(1,100,100,100,100);
    cout<<ans<<endl;
    }
}