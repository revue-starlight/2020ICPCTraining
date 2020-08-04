#include <bits/stdc++.h>
using namespace std;
bool parked[3][100004];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long T;
    cin>>T;
    while (T--){
        long long n;
        memset(parked,0,sizeof(parked));
        cin>>n;
        long long l=0,r=0;
        for (int i=1;i<=n;i++){
            long long a,b;
            cin>>a>>b;
            parked[a][b]=1;
            if (a==1 && b>r) r=b;
            if (a==2 && b>l) l=b; 
        }
        long long ans=0;
        if (n==1 && parked[1][1]==1)    {cout<<2<<endl; continue;}
        ans=max(l+2,r+1);
        if (parked[1][l+1]==true) ans=max(ans,l+3);
        cout<<ans<<endl;
    }

}