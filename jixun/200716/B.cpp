#include <bits/stdc++.h>
using namespace std;
const int N=2006;
struct Node{
    int x,y;
}node[N];
#define ll long long
struct Pair{
    pair<int,int> p;
    int zf;
};

inline ll gcd(int x,int y){
    if (y==0) return x; else return gcd(y,x%y);
}

inline Pair cal_cos(int x1,int y1,int x2,int y2,int x3,int y3){
    Pair pa;
    int a=(y3-y2)*(y3-y2)+(x3-x2)*(x3-x2);
    int b=(y2-y1)*(y2-y1)+(x2-x1)*(x2-x1);
    int c=(y3-y1)*(y3-y1)+(x3-x1)*(x3-x1);
    ll x=c+b-a;
    if (x>0) pa.zf=1; else if (x<0) pa.zf=-1; else pa.zf=0;
    x=x*x;
    ll y=4*b*c;
    ll gcdd=gcd(x,y);
    if (gcdd==0) {pa.p.first=0; pa.p.second=1; return pa;}
    pa.p.first=x/gcdd;
    pa.p.second=y/gcdd;
    return pa;
}

inline int dir(int x1,int y1,int x2,int y2,int x3,int y3){
    int tmp=(x1-x3)*(y2-y3)-(y1-y3)*(x2-x3);
    return tmp;
}

map <pair<int,int>,int> mp;
map <pair<int,int>,int> mp2;
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>node[i].x>>node[i].y;
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        mp.clear();
        mp2.clear();
        int guoyuanxin=0;
        int maxx=-1;
        for (int j=1;j<=n;j++){
            if (i==j) continue;
            Pair p=cal_cos(node[j].x,node[j].y,0,0,node[i].x,node[i].y);
            int kk=dir(0,0,node[i].x,node[i].y,node[j].x,node[j].y);
            if (kk>0 && p.zf<0 || kk<0 && p.zf>0) {
                pair <int,int> tmp; tmp.first=p.p.first; tmp.second=p.p.second;
                mp[tmp]++;
                maxx=max(maxx,mp[tmp]);
            }
            if (kk<0 && p.zf<0 || kk>0 && p.zf>0) {
                pair <int,int> tmp; tmp.first=p.p.first; tmp.second=p.p.second;
                mp2[tmp]++;
                maxx=max(maxx,mp[tmp]);
            }
            if (p.zf==0){
                guoyuanxin++;
            }
        }
        if (guoyuanxin>maxx) maxx=guoyuanxin;
        ans=max(ans,maxx);
    }
    cout<<ans+1<<endl;
}