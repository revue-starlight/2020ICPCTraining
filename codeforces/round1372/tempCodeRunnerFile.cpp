#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+10;
ll a[maxn];
ll nd[maxn],od[maxn];
int main(){
    int n;
    ll tot=0,sum1=0,sum2=0;
    cin>>n;
    for (int i=1;i<=n;i++) {cin>>a[i]; tot+=a[i];}
    for (int i=n+1;i<=n*2;i++) a[i]=a[i-n];
    for (int i=1;i<=n*2;i++) 
        if (i%2) od[i/2+1]=od[i/2]+a[i];
        else nd[i/2]=nd[i/2-1]+a[i];
    ll minn=LONG_LONG_MAX;
    for (int i=n/2;i<=n;i++){
        minn=min(minn,od[i]-od[i-n/2]);
        minn=min(minn,nd[i]-nd[i-n/2]);
    }
    cout<<tot-minn<<endl;
}