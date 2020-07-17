#include <iostream>
#include <algorithm>
using namespace std;
long long q,n,x,y,a,b;
long long ans,k;
long long p[200002];
long long prog,proa,prob;
bool cmp(const long long a,const long long b){return a>b;}
long long gcd(long long a,long long b)
{
    if (b==0) return a; 
        else return gcd(b,a%b);
}

bool check(long long n)
{
    long long g=a*b/gcd(a,b);
       prog=n/g,proa=n/a,prob=n/b;//最多能卖多少票（有价值的）
       proa=proa-prog; prob=prob-prog;
    if (x<y) {swap(a,b); swap(x,y); swap(proa,prob);}
    long long ans=0;
    for (long long i=1;i<=prog;i++)
    {
        ans+=p[i]/100*(x+y);
    }
    for (long long i=prog+1;i<=prog+proa;i++)
    {
        ans+=p[i]/100*x;
    }
    for (long long i=prog+proa+1;i<=prog+proa+prob;i++)
    {
        ans+=p[i]/100*y;
    }
    if (ans>=k) return true; else return false;

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>q;
        for (long long CASE=1;CASE<=q;CASE++)
{
        cin>>n;
        for (long long i=1;i<=n;i++)
            cin>>p[i];
    sort(p+1,p+1+n,cmp);
    cin>>x>>a>>y>>b>>k;
    long long l=1,r=n;
    if (!check(n)) {cout<<"-1"<<endl; continue;}
    while (l<r)
    {
        long long mid=(l+r)/2;
        if (check(mid)) 
         r=mid; 
            else l=mid+1;
    }
    cout<<l<<endl;
}

}