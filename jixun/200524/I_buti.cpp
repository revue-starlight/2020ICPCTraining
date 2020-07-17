#include <bits/stdc++.h>
using namespace std;
int a[1000007];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int s=0,t=n+1;
    int p=1;
    while (a[p+1]>=a[p] && p<n) p++;
    if (p==n)  {cout<<1<<" "<<1; return 0;}
    while (a[p]==a[p-1] && p-1>=1) p--;
    s=p;
    p=n;
    while (a[p]>=a[p-1] && p>1) p--;
    while (a[p]==a[p+1] && p+1<=n) p++;
    t=p;
    if ((s>1 && t<n) && (a[s]>a[t+1] || a[t]<a[s-1])) {cout<<"impossible"; return 0;}
    for (int i=s+1;i<=t;i++){
        if (a[i]>a[i-1]) {cout<<"impossible"; return 0;}
    }
    cout<<s<<" "<<t;
}