#include <bits/stdc++.h>
using namespace std;
const double rk[11]={0,1.0,1.7,2.0,2.3,2.7,3.0,3.3,3.7,4.0,4.3};
const int sco[11]={0,60,62,65,67,70,75,80,85,90,95};

double solve(int x){
    double ans=0;
    for (int i=0;i<11;i++)
        for (int j=0;j<11;j++)
            for (int k=0;k<11;k++)
                for (int l=0;l<11;l++)
                {
                    if (sco[i]+sco[j]+sco[k]+sco[l]>x) continue;
                    else ans=max(ans,rk[i]+rk[j]+rk[k]+rk[l]);
                }
    return ans;
}
int main(){
    int T;
    cin>>T;
    while (T--){
        int x;
        cin>>x;
        double a=solve(x);
        cout<<fixed<<setprecision(1)<<a<<endl;
    }
}