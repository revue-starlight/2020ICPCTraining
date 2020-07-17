#include <bits/stdc++.h>
#define MAXN 200001
using namespace std;
struct node{
    int x,ji;
}a[MAXN];

bool cmp (node a,node b)
{
    if (a.ji==b.ji) return a.x>b.x; else return a.ji>b.ji;
}
int main()
{
    int t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            int xx;
            cin>>xx;
            int t=0;
            while (!(xx%2)) {t++; xx=xx/2;}
            a[i].x=t; a[i].ji=xx;
        }
        sort(a+1,a+1+n,cmp);
        int t=1,ans=0;
        while (t<=n)
        {
            int re=a[t].ji;
            ans+=a[t].x;
            while (a[t].ji==re) t++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
 