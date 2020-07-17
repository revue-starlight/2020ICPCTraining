
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <ctime>
#include <cctype>
#include <bitset>
#include <utility>
#include <sstream>
#include <complex>
#include <iomanip>
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;
const ll mod=1000000007;
int A,B,C,K;
ll ls,jg;
ll ksm(int a,ll b,ll mod)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans%mod*a%mod)%mod;
        a=(a%mod*a%mod)%mod;
        b>>=1;
    }
    return ans;
}
ll plzh(int n,int m)
{
    ll ans=1;
    int ls=m;
    while(ls)
    {
        ans=(ans%mod*n%mod)%mod;
        n--;
        ls--;
    }
    return ans;
}
int main()
{
    cin>>A>>B>>K>>C;
    if(C!=A&&C!=B)
        cout<<0<<endl;
    else if(A==B)
        cout<<K<<endl;
    else
    {
        for(int i=1; i<=K; i++)
        {
            ls=(i%mod*plzh(K,i)%mod*ksm(plzh(i,i),mod-2,mod)%mod)%mod;
            jg=(jg%mod+ls)%mod;
        }
        cout<<jg<<endl;
    }
    return 0;
}