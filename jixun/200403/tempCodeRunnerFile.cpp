#include <iostream>
using namespace std;
#define maxn 200015
#define mod 1000000007
#define ll unsigned long long
ll lj[maxn];
ll ans;
int main(){
    int n;
    scanf("%d",&n);
    char ch;
    getchar();
    for (int i=1;i<=n;i++){
        scanf("%c",&ch);
        if (ch=='0') lj[i]=lj[i-1];
        else lj[i]=i;
    }

    for (int i=1;i<=n;i++){
        ll x=lj[i];
        ll ans1;
        ans1=(2*i-lj[i]+1)*lj[i]/2*lj[i];
        ans1=(ans1+ans)%mod;
    }
    printf("%lld",ans);
}