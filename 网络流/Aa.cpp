#include <iostream>
using namespace std;
const int maxn=101;

int n,m,k;
int cx[maxn],cy[maxn],vis[maxn];
int mp[maxn][maxn];
bool hungary(int x){
	for (int i=1;i<m;i++){
		if (mp[x][i] && !vis[i]){
			vis[i]=1;
			if (cy[i]==-1 || hungary(cy[i])){
				cy[i]=x;
				cx[x]=i;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int ans=0;
	while (cin>>n){
		ans=0;
		memset(mp,0,sizeof(mp));
		memset(cx,-1,sizeof(cx));
		memset(cy,-1,sizeof(cy));
		if (n==0) break;
		cin>>m>>k;
		while (k--){
			int id,aa,bb;
			cin>>id>>aa>>bb;
			if (aa!=0 && bb!=0) 
			mp[aa][bb]=1;
		}
		for (int i=1;i<n;i++){
			memset(vis,0,sizeof(vis));
			if (hungary(i)) ans++;
		}
		cout<<ans<<endl;
	}
}