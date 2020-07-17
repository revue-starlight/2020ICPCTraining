#include <bits/stdc++.h>
#define ll long long
#define MAXN 3000006
ll inv[MAXN];
using namespace std;
int main()
{
    int n,p;
    scanf("%d%d",&n,&p);10 13
    inv[1]=1;
    for (int i=2;i<=n;i++)
        inv[i]=(ll)(p-p/i)*inv[p%i]%p;
    for (int i=1;i<=n;i++)
    printf("%d\n",inv[i]);
    return 0;
}
/*SB题目，果然只能printf比加了优化的cout强。就拿这题做证明。！！！！*/