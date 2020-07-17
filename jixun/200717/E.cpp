#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll ys[15][2];
ll zt[15];
bool  downing[15];
ll zt_tar[15];
ll n;
ll ans=1;


int main(){
    cin>>n;
    ll tar=1;
    for (ll i=1;i<=n;i++){
        cin>>ys[i][0]>>ys[i][1];
        tar=tar*(1+ys[i][1]);
    }
    zt_tar[1]=1;
    for (ll i=2;i<=n;i++){
        zt_tar[i]=(zt_tar[i-1])*(ys[i-1][1]+1);
    }
    ll tmp=1;
    memset(zt,0,sizeof(zt));
    while (1){
        cout<<ans<<endl;
        if (tmp>=tar) break;
        ll k=1;
        if (tmp!=0)
            for (k=n;k>=1;k--) if (tmp % zt_tar[k]==0) break;
        if (k==n || downing[k]==false) {
            zt[k]++;
            ans=ans*ys[k][0];
            tmp++;
            if (zt[k]==ys[k][1]) downing[k]=true;
        }
        else {
            zt[k]--;
            ans=ans/ys[k][0];
            tmp++;
            if (zt[k]==0) downing[k]=false;
        }
    }
}