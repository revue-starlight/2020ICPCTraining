#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[3];
int main(){
    int n;
    cin>>n;
    while (n--){
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
    int ans;
    ans=INT_MAX;
    int b1,b2,b3;
    b1=b2=b3=1000;

    //1.
    if (a[1]==a[2]){
    int round=0;
    if (1000%a[2]==0) round=1000/a[2];
    else round=1000/a[2]+1;
    ans=min(ans,round);
    }
    else
    {
        int round=0;
        if (1000%a[2]==0) round=1000/a[2];
        else round=1000/a[2]+1;
    // 2,3互殴
        b1=1000;
        b2=0;
        b3=1000-round*(a[1]);
        int tmp=INT_MAX;
        int tmp1;
        if (b3<0) tmp=0;
        if (b3%a[0]==0) tmp=b3/a[0];
        else tmp=b3/a[0]+1;
        if (b1%a[2]==0) tmp1=b1/a[2];
        else tmp1=b1/a[2]+1;
        tmp=min(tmp,tmp1);
        round+=tmp;
        ans=min(ans,round);
    // 1,2互殴
        if (1000%a[2]==0) round=1000/a[2];
        else round=1000/a[2]+1;
        b1=0;
        b2=1000;//b2补b3
        b3=1000-round*(a[0]);
        if (b3<0) tmp=0;
        tmp=INT_MAX;
        if (b3%a[0]==0) tmp=b3/a[0];
        else tmp=b3/a[0]+1;
        if (b2%a[2]==0) tmp1=b2/a[2];
        else tmp1=b2/a[2]+1;
        tmp=min(tmp,tmp1);
        round+=tmp;
        ans=min(ans,round);
    }
        if (a[0]==a[1]){
            int tmp;
            if (1000%a[0]==0) tmp=1000/a[0]; else tmp=1000/a[0]+1;
            ans=min(ans,tmp);
        }

        b1=1000-(1000/a[3])*a[3];
        b2=1000-(1000/a[3])*a[3];
        if
        
        cout<<ans<<endl;
    }
}