#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[1001];
    memset(a,0,sizeof(a));
    int n;
    while (cin>>n){
        int sum=0;
        int maxx=-INT_MAX;
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++){
            cin>>a[i];
            if (maxx<a[i]) maxx=a[i];
            sum+=a[i];
        }
        sum-=maxx;
        if (sum<=maxx)  {double ans=sum; cout<<fixed<<setprecision(1)<<ans<<endl;}
        else {double ans=(sum+maxx); ans/=2; cout<<fixed<<setprecision(1)<<ans<<endl;}
    }
}