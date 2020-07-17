#include <bits/stdc++.h>
using namespace std;
int a[150],n,k,ans[150];
bool b[100];
bool breakk=false;
void dxs(int k)
{
    int ans=1;
    a[0]=1; a[k]=1;
    for (int i=1;i<=k/2;i++)
    {
        ans=ans*(k-i+1)/i;
        a[i]=ans; a[k-i]=ans;
    }
}


void dfs(int n,int t)
{
    if (k==t && n==0)
    {
        for (int i=0;i<t;i++) cout<<ans[i]<<" ";
         breakk=true; return;
    }
    if (k==t || breakk) return;
    for (int i=1;i<=n/a[t] ;i++)
    {
        if (i>k) break;
        if (n-a[t]*i>=0 && !b[i])
        {
            ans[t]=i;
            b[i]=1;
            dfs(n-a[t]*i,t+1);
            if (breakk) return;
            b[i]=0;
        }
    }
}
int main()
{
    cin>>k>>n;
    dxs(k-1);
 //   cout<<b[1];
 //   for (int i=0;i<k;i++) cout<<a[i]<<endl;
    dfs(n,0);
}