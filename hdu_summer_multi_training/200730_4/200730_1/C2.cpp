#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5+10;
struct node{
    ll hapy,tot;
    ll hpiness;
    ll lev;
    ll fth;
    vector <ll> vec;
}tree[N];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    ll T;
    cin>>T;

    while (T--){
    ll n,m;
    cin>>n>>m;
    for (ll i=1;i<=n;i++){
        cin>>tree[i].tot;
        tree[i].vec.clear();
        tree[i].hapy=tree[i].lev=0;
    }
    for (ll i=1;i<=n;i++)
        cin>>tree[i].hpiness;
    
    for (ll i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        tree[x].vec.push_back(y);
        tree[y].vec.push_back(x);
    }

    queue <ll> q;
    stack <ll> stk;
    q.push(1);
    stk.push(1);
    tree[1].lev=1;
    ll level;
    while (!q.empty()){
        ll x=q.front(); q.pop();
            level=tree[x].lev;
        ll len=tree[x].vec.size();
        for (ll i=0;i<len;i++){
            if (!tree[tree[x].vec[i]].lev){
            tree[tree[x].vec[i]].lev=level+1;
            tree[tree[x].vec[i]].fth=x;
            q.push(tree[x].vec[i]);
            stk.push(tree[x].vec[i]);
            }
        }
    }
    bool bo=true;
    while (!stk.empty()){
        ll x=stk.top(); stk.pop();
            if ((tree[x].tot+tree[x].hpiness)%2!=0) {bo=false; cout<<"NO"<<endl; break;}
        ll q=(tree[x].tot+tree[x].hpiness)/2;
        if (q<tree[x].hapy) {bo=false; cout<<"NO"<<endl; break;}
        tree[tree[x].fth].hapy+=q;
        tree[tree[x].fth].tot+=tree[x].tot;
    }
    if (bo) cout<<"YES"<<endl;
    }
}