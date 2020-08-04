#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=500005;
struct node{
    ll a,p;
}rob[maxn];

inline bool cmp(node a,node b){
    if (a.a==b.a) return a.p>b.p;
    else return a.a<b.a;
}

inline bool check(node a,node b,node c){
    ll aa=b.p-c.p;
    ll bb=c.a-b.a;
    ll cc=a.p-c.p;
    ll dd=c.a-a.a;
    if (aa*dd>=bb*cc) return false;
    else return true;
}

void solve(){
    ll n;
    map <ll,ll> mp;
    mp.clear();
    stack <node> s;
    cin>>n;
    ll robpmax=-1;
    ll robpid;
    for (ll i=1;i<=n;i++){
        cin>>rob[i].p>>rob[i].a;
        
        if (rob[i].p==robpmax && rob[i].a>robpid) {robpid=rob[i].a;} 
        if (rob[i].p>robpmax) {robpmax=rob[i].p; robpid=rob[i].a; }
    }
    sort(rob+1,rob+1+n,cmp);
    for (ll i=1;i<=n;i++){
        if (s.empty()) s.push(rob[i]);
        else{
            if (rob[i].a==s.top().a) {
                    if (rob[i].p==s.top().p) mp[rob[i].a]=1;
                    continue;
            }

            if (s.size()==1)
                s.push(rob[i]);
            else{
                while (1){
                node tmp=s.top(); s.pop();
                if (s.empty() || check(rob[i],tmp,s.top())) {s.push(tmp); s.push(rob[i]); break;}
                }
            }
        }
    }
    ll ans=s.size();
    ll ans2=0;
    while (!s.empty())
    {
        if (mp[s.top().a]) ans2++;
        if (s.top().a==robpid) break;
        s.pop();
    }
    cout<<ans-ans2-s.size()+1<<endl;
}
int main(){
    //freopen("datastd.in","r",stdin);
    //freopen("a.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
   ll T;
   cin>>T;
   while (T--) solve();
} 