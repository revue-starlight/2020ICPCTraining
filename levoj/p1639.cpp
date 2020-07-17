#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
#define mod 1000000007
#define maxn 1000000
using namespace std;
LL pre[maxn][20],val_pre[maxn][20],suf[maxn][20],val_suf[maxn][20];
LL a[maxn];
int n;
void prework()
{
    int x=0;
    for (int i=1;i<=n;i++)
    {
        x^=a[i];
        for (int j=0;j<20;j++)
        {
            pre[i][j]=pre[i-1][j];
            val_pre[i][j]=(bool)(1<<j)&x;
            if ((1<<j)&a[i]) pre[i][j]++;
        }
    }
    x=0;
    for (int i=n;i>=1;i--)
    {
        x^=a[i];
        for (int j=0;j<20;j++)
        {
            suf[i][j]=suf[i+1][j];
            val_suf[i][j]=(bool)x&(1<<j);
            if ((1<<j)&x) suf[i][j]++;
        }
    }
}


LL get_pre(int l,int r,int pos,int val)
{	
	int res,cur=pre[r][pos]-pre[l-1][pos]; 
    //右端点1的数量减去左端点1的数量。区间内有多少个1
	if (val_pre[l-1][pos]) cur=r-l+1-cur;	
    // 如果pos位置为1 cur=(r-l+1)-cur
	if (val) res=cur; else res=r-l+1-cur;
    //返回答案啊
	return res;
}

LL get_suf(int l,int r,int pos,int val)
{	
	int cur=suf[l][pos]-suf[r+1][pos];
	if (val_suf[r+1][pos]) cur=r-l+1-cur;	
	if (val) return cur; else return r-l+1-cur;
}

LL calc(int l,int mid,int r)
{
	ll ans=0;
	for (int i=0;i<=19;i++)
	{
		ans+=(1<<i)%mod*(get_suf(l,mid,i,1)*get_pre(mid+1,r,i,0)+get_suf(l,mid,i,0)*get_pre(mid+1,r,i,1))%mod;
	}
	return ans;
}


LL getans(int l,int r)
{
    int mid=(l+r)/2;
    if (l==r) return 0;
    return getans(1,mid)%mod+getans(mid+1,r)%mod+calc(1,r)%mod;
}


int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    prework();
    cout<<getans(1,n)<<endl;
}