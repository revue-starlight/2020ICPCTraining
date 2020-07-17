#include <bits/stdc++.h>
using namespace std;
#define maxn 106
int s,t;
int a[maxn];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    s=1;
    for (int i=2;i<=n;i++){
        if (a[i]>=a[i-1]) s=i;
        else break;
    }
    if (s==n) {cout<<"1 1"; return 0;}
    t=n;
    for (int i=n;i>=2;i--){
        if (a[i]>=a[i-1]) t=i-1;
        else break;
    }
    while (a[s]==a[s-1] && s-1>=1) {s--;}
    while (a[t]==a[t+1] && t+1<=n) t++;
    if ((s>1 && t<n) && (a[s]>a[t+1] || a[t]<a[s-1])) {cout<<"impossible"; return 0;}
    for (int i=s+1;i<=t;i++) if (a[i]>a[i-1]) {cout<<"impossible"; return 0;}
    cout<<s<<" "<<t<<endl;
 }