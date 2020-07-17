#include <bits/stdc++.h>
#define ll long long
#define maxn 200001
using namespace std;
ll n,a[maxn],pre[maxn],last[maxn];
int main(){
    scanf("%d",&n);
    ll t;
    scanf("%d",&t);
    for (ll i=2;i<=n;i++) scanf("%d",a+i),a[i]-=t;
    sort(a+1,a+1+n);
    for (ll i=2;i<=n;i++) pre[i]=a[i]+pre[i-1];
    double x=(double)pre[n]/n;
    ll i=1;
    double ans=0;
    while (a[i]<x){
        ans+=(a[i]-x);
        i++;
    }
    printf("%.12lf",ans);
}