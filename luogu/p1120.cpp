#include <iostream>
using namespace std;
int maxx,sum,minn=0x3f3f3f3f,n,k,a[51],check,cnt;
bool bo=false;
void search(int x,int k)
{
	if(cnt==0) {printf("%d",check); exit(0);}
	if (x==check) {search(0,maxx);}

	for (int i=k;i>=minn;i--)
	{
		if (a[i]>0 && i+x<=check) {
			a[i]--; cnt--; search(x+i,i); a[i]++; cnt++;
				if (x==0 || x+i==check) break;
		}
	}
}

int main()
{
	int t=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x);
		if (x<=50) {
			t++;
			sum+=x;
			a[x]++;
			if (maxx<x) maxx=x;
			if (minn>x) minn=x;
		}
	}
	n=t;
	check=maxx;
	cnt=n;
	while(1)
	{
		while (sum%check!=0) check++;
		if (check==sum) {cout<<sum<<endl; return 0;}
	/*	if (check==70)
		{55
4 5 1 3 1 1 1 5 7 6 8 1 7 5 3 6 6 2 5 6 8 1 7 2 6 8 7 5 5 2 1 5 6 1 8 8 4 1 2 4 2 4 7 5 1 1 8 5 2 4 8 5 7 4 3

			cout<<"here it is"<<endl;
		} */
		search(0,maxx);
		check++;
		//cout<<check;
		if (bo) return 0;
	}
	
}