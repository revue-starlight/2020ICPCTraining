#include <bits/stdc++.h>
using namespace std;
map <long long,long long> m1;
long long n,m;
long long a[100002];
int main()
{
    cin>>n>>m;
    int x[100002],y[100002];
    for (int i=1;i<=n;i++) cin>>x[i];
    for (int i=1;i<=m;i++)
    {
        cin>>y[i];
        m1[y[i]]=1;
    }
    for (int i=1;i<=n;i++)
    {
        if (m1[x[i]]==1) cout<<x[i]<<" ";
    }
    return 0;
}