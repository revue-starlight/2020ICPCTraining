#include <bits/stdc++.h>
using namespace std;
#define MAXN 10000
bool notp[MAXN];
int prime[MAXN],tot;
int main()
{
    notp[1]=1;
    for (int i=2;i<=MAXN;i++)
    {
        if (notp[i]==0) prime[++tot]=i;
        for (int j=1;j<=tot;j++)
        {
            if (i*prime[j]>MAXN) break;
            notp[prime[j]*i]=1;
            if (i%prime[j]==0) break;
        }
    }
    int n;
    while (cin>>n)
    {
        while (n>1)
        {
            for (int i=1;i<=tot;i++)
            {
                if (n%prime[i]==0) {n/=prime[i]; cout<<prime[i]<<" "; break;}
            }
        }
        cout<<endl;
    }
    return 0;
}