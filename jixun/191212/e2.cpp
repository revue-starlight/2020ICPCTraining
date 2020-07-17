#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int m,n,k,t,a[200010],vis[200010],l,r,road[200010];
struct node{int l,r,d;}d[200010];
int cmp(int a,int b){return a>b;}

int check(int mid){
	int low_bound=a[mid],sum=0; memset(road,0,sizeof(road));
	for(int i=1;i<=k;i++)	if(d[i].d>low_bound){road[d[i].l]++,road[d[i].r+1]--;}
	for(int i=1;i<=n+1;i++)	road[i]+=road[i-1];
	for(int i=0;i<=n+1;i++)	sum+=(road[i]>=1);
	return sum*2+n+1<=t;
}
signed main(){
	cin>>m>>n>>k>>t; l=0,r=m;
	for(int i=1;i<=m;i++)	scanf("%d",&a[i]);
	for(int i=1;i<=k;i++)	scanf("%d %d %d",&d[i].l,&d[i].r,&d[i].d);
	sort(a+1,a+1+m,cmp);
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid))	l=mid;
		else	r=mid-1; 
	}
	cout<<l<<endl;
	return 0;
}