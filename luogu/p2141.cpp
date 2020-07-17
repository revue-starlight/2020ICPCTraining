#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001
int n,a[MAXN],sum;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {cin>>a[i];}
    sort(a+1,a+1+n);
    for (int i=3;i<=n;i++)
    {
        bool bo=false;
        for (int j=2;j<i;j++)
        {
            for (int k=1;k<j;k++)
                {
                    if (a[k]+a[j]==a[i]) {sum++; /*cout<<a[k]<<"+"<<a[j]<<"="<<a[i]<<endl; */ bo=true; break;}
                    if (a[k]+a[j]>a[i]) break;
                }
            if (bo) break;
        }
    }
    cout<<sum<<endl;
    return 0;
}