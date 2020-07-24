#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
struct node{
    int a,b,c,d;
};
vector <node> vec[51];
node sett[51];
ll ans=-1;

int main(){
     ll T;
    cin>>T;
    while (T--){
    ans=-1;
    cin>>n>>k;
    for (int i=0;i<=50;i++){
        vec[i].clear();
    }
    for (int i=0;i<=n;i++){
        sett[i].a=sett[i].b=sett[i].c=sett[i].d=0;
    }
    for (ll i=1;i<=n;i++){
        ll type;
        cin>>type;
        node tmp;
        cin>>tmp.a>>tmp.b>>tmp.c>>tmp.d;
        vec[type].push_back(tmp);
    }
    int tmpa=100,tmpb=100,tmpc=100,tmpd=100;
    
    for (int i=1;i<=k;i++){
        int maxx=-1;
        int maxa=0,maxb=0,maxc=0,maxd=0;
        for (int j=0;j<vec[i].size();j++){
            int aa=tmpa+vec[i][j].a;
            int bb=tmpb+vec[i][j].b;
            int cc=tmpc+vec[i][j].c;
            int dd=tmpd+vec[i][j].d;
        if (maxx<(aa*bb*cc*dd)){
            maxx=aa*bb*cc*dd;
            maxa=aa; maxb=bb; maxc=cc; maxd=dd;
            }
        }
        tmpa+=maxa; tmpb+=maxb; tmpc+=maxc; tmpd+=maxd;
    }
    cout<<tmpa*tmpb*tmpc*tmpd<<endl;
    }
}