#include <bits/stdc++.h>
using namespace std;
int a[1000001];
vector <int> v;
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=2;i<=n;i++)
    {
        v.push_back(a[i]-a[i-1]);
    }
    for (int i=1;i<=m;i++)
    {
        int k=n-2;
        int minn=INT_MAX,t=0;
            for (int j=0;j<=k;j++)
            {
                if (v[j]<minn){
                    minn=v[j];
                    t=j;
                }
            }
        v.erase(t);
        k--;
    }
    int minn=INT_MAX;
    for (int i=0;i<=k;i++)
    {
        if (v[i]<minn) minn=v[i];
    }
    cout<<minn;
    return 0;
}