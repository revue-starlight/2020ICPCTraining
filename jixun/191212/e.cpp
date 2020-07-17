#include <bits/stdc++.h>
using namespace std;
struct node{
    int l,r,d;
}s[200001];
int a[200001];

bool cmp(node a,node b)
{
    return a.d>b.d;
}
int main()
{
    ios::sync_with_stdio(false);    cin.tie(0);
    int m,n,k,t;
    cin>>m>>n>>k>>t;
    for (int i=1;i<=m;i++)
        cin>>a[i];
        sort(a+1,a+1+m);
    for (int i=1;i<=k;i++)
    {
        cin>>s[i].l>>s[i].r>>s[i].d;
    }
    sort(s+1,s+1+k,cmp);
    t-=(n+1);
    int trap=1,soilder=m;
    while (1)
    {
        while (a[soilder]>=s[trap].d && soilder>=1) soilder--;
        if (soilder==0) {cout<<m<<endl; return 0;}
        while (s[trap].d>=a[soilder])
        {
            //要拆trap救命
            if (s[trap].r>s[trap].l)
            {t-=(s[trap].r-s[trap].l)*2;
            trap++;
            if (t<0) {cout<<m-soilder<<endl; return 0;}
            }
            else trap++; 
        }
    }

          
}