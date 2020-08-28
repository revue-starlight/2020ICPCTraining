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
    for (ll i=1;i<=n;i++){
        ll type;
        cin>>type;
        node tmp;
        cin>>tmp.a>>tmp.b>>tmp.c>>tmp.d;
        vec[type].push_back(tmp);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++)
    }
    cout<<ans<<endl;
    }
}