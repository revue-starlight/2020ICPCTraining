#include <bits/stdc++.h>
using namespace std;
vector <int> vec;
int main(){
    int n;
    while (cin>>n){
        int maxx=-0x3f3f3f3f,minn=0x3f3f3f3f,tot=0;
        for (int i=1;i<=n;i++){
            int a;
            cin>>a;
            if (a>maxx) maxx=a;
            if (a<minn) minn=a;
            tot+=a;
        }
        tot=tot-maxx-minn;
        double ans=(double)tot/(n-2);
        ans=ans*100;
        ans=round(ans);
        ans=ans/100;
        printf("%.2lf\n",ans);
    }
}