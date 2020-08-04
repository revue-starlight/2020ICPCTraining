#include <bits/stdc++.h>
using namespace std;
int b[101];
double c[101];
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++) cin>>b[i]>>c[i];
        double ans=0;
        for (int i=1;i<=n;i++)
        ans=max(ans,(1-c[i])/(b[i]+1-c[i]));
        printf("%.5lf\n",ans);
    }
}