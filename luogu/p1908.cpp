/* BANZAI*/
#include <iostream>
using namespace std;
long long a[1000010];
long long ans;
long long b[1000010];
void work(long long l,long long r)
{
	if (l==r) return;
	long long mid=(l+r)/2;
	long long pos1=l,pos2=mid+1,cur=0;
	work(l,mid); work(mid+1,r);
	while (pos1<=mid && pos2<=r)
	{
		if (a[pos2]<a[pos1]) {
		b[++cur]=a[pos2]; 	pos2++; 
		}
		else {
			ans+=pos2-mid-1; 
			b[++cur]=a[pos1];
			pos1++; 
		}
	}
	while (pos1<=mid)
	{
		b[++cur]=a[pos1];
		pos1++; 
		ans+=pos2-mid-1;
	}
	while (pos2<=r)
	{
		b[++cur]=a[pos2];
		pos2++;
	}
	
	for (long long i=l;i<=r;i++)
	{
		a[i]=b[i-l+1];
	}
}

int main()
{
	long long n;
	cin>>n;
	for (long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	work(1,n);
	cout<<ans;
}