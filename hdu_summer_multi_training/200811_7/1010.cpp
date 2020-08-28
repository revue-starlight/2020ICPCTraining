#include <bits/stdc++.h>
using namespace std;
#define ll long long
inline ll gcd(ll a,ll b){
    return b>0 ? gcd(b,a%b):a;
}
bool in_graph(ll a,ll b){
    if (a<=0 || b<=0) return false;
    else return true;
}

const ll fx[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
struct node{
    ll x,y;
    bool operator <(const node &rhs) const  {
        return x < rhs.x || (x == rhs.x && y < rhs.y);

    }
};
queue <node> q;
void solve(ll T){
    bool bo=true;
    node p;
    while (!q.empty()) q.pop();
    ll fenmu;
    cin>>p.x>>p.y;
    q.push(p);
    ll bianshu=0;
    ll jiedianshu=1;
    map <node,int> mp;
    mp[p]=T;
    while (!q.empty()){
        node x=q.front(); q.pop();
        for (ll i=0;i<8;i++){
            ll tx=x.x+fx[i][0],ty=x.y+fx[i][1];
            if (tx==ty) {bo=false; cout<<"0/1"<<endl; break;}
            node tmp2; tmp2.x=tx; tmp2.y=ty;
            if (in_graph(tx,ty) && gcd(tx,ty)>1){
                bianshu+=1;
                if (mp[tmp2]!=T){
                  //  cout<<tx<<" "<<ty<<endl;
                    jiedianshu+=1;
                mp[tmp2]=T;
                q.push(tmp2);
                }
            }
            
        }
        if (!bo) break;
    }
    ll fz=0;
    for (ll i=0;i<8;i++){
        node tmp;
        tmp.x=p.x+fx[i][0]; tmp.y=p.y+fx[i][1];
        if (mp[tmp]==T) fz++;
    }
    fz++;

    if (bo){
        ll fm=jiedianshu+bianshu;
        ll gcdd=gcd(fz,fm);
        cout<<fz/gcdd<<"/"<<fm/gcdd<<endl;
    }
}
int main(){
    ll T;
    cin>>T;
    while (T--) solve(T+1);
}