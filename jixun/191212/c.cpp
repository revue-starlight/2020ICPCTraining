#include <iostream>
#include <algorithm>
using namespace std;
int t,n,a[2001],m,s[2001],p[2001];
int c[2001]; //i持久度下最大力量。
/*struct node{
    int p,s;
}
bool cmp(node a,node b)
{
    if (a.s==b.s) return a.p>b.p;
    return a.s>b.s;
}*/
bool bo=true;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>t;
    for (int CASE=1;CASE<=t;CASE++)
    {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        cin>>m;
        for (int i=1;i<=m;i++) cin>>p[i]>>s[i];
        for (int i=1;i<=n;i++) c[i]=0;
        for (int i=1;i<=m;i++)
            if (p[i]>c[s[i]]) c[s[i]]=p[i];
        
        for (int i=n-1;i>=1;i--)
            if (c[i]<c[i+1]) c[i]=c[i+1]; //该持久度下的最大力量

        int pos=1,ans=0;
        while (pos<n)
        {
            ans++;
            int l=pos,r=n,maxx,mid;
            if (c[1]<a[pos]) {cout<<"-1"<<endl; bo=false; break;}
            while (l<r)
            {    maxx=-1;
                 mid=(l+r+1)/2;
                for (int i=pos;i<=mid;i++) if (p[i]>maxx) p[i]=maxx;
                if (c[mid-pos+1]>=maxx) l=mid;
                else r=mid-1;
            }
            pos=l+1;
        }
        if (!bo) continue;
        cout<<ans<<endl;
    }
    return 0;
}