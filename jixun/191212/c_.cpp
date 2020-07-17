#include <iostream>
#include <algorithm>
using namespace std;
int t,n,a[200001],m,s[200001],p[200001];
int c[200001];
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
        //read ^ sjcl v

        for (int i=1;i<=n;i++) c[i]=0;
        for (int i=1;i<=m;i++)  if (p[i]>c[s[i]]) c[s[i]]=p[i];
        for (int i=n-1;i>=1;i--) if (c[i]<c[i+1]) c[i]=c[i+1];
        
        int pos=1,maxx=-1,i=1,ans=1; bool bo=true;
        while (pos<=n)
        {
          //  if (i==1 && c[1]<a[pos]) {cout<<"-1"<<endl; bo=false; break;}
            if (maxx<a[pos]) maxx=a[pos];
            if (c[i]>=maxx) {i++; pos++;}
            else {
                if (i==1) {cout<<"-1"<<endl; bo=false; break;}
                ans++;
                i=1;
                maxx=-1;
            }
        }
        if (bo) cout<<ans<<endl; 
    }
}