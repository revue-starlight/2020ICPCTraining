#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y;

ll work(ll c,ll k)
{
    if (c==k) return c*4;
    if (c-k>k) return k*4+work(c-k,k); else return k*4+work(k,c-k);
}

int main()
{
    ll sum=0;
    cin>>x>>y;
    while (x!=0)
    {
        if (x<y) swap(x,y);
        sum+=4*y*(x/y);
        x=x-(x/y)*y;
    }
    cout<<sum;
}