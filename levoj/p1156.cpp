#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#define mod 9973
int a[10][10];
int n,k;

	int ans[10][10];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
void ksm(int k){
	int b[10][10];
	memset(ans,0,sizeof(ans));
	for (int i=1;i<=n;i++) ans[i][i]=1;
	
	while (k!=0){
		int temp[10][10];
        memset(temp,0,sizeof(temp));
		if (k%2==1) {
			// ans*=a;
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
				{
					for (int k=1;k<=n;k++)
					temp[i][j]=(temp[i][j]+ans[i][k]*a[k][j])%mod;
				}
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
				ans[i][j]=temp[i][j];
		}
		k/=2;
		memset(b,0,sizeof(b));
        //a自乘
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			{
				for (int k=1;k<=n;k++)
					b[i][j]=(b[i][j]+a[i][k]*a[k][j])%9973;
			}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			a[i][j]=b[i][j];
            
            /*cout<<"k="<<k<<endl;
        for (int i=1;i<=n;i++){
			for (int j=1;j<n;j++) printf("%5d",ans[i][j]);
			printf("%5d\n",ans[i][n]);
        }*/
	}
	
	
}
int main(){
	int T;
	while (cin>>T){
        
        while (T--){
		cin>>n>>k;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++){
				cin>>a[i][j];	
			}
		ksm(k);
		/*for (int i=1;i<=n;i++){
			for (int j=1;j<n;j++) printf("%4d",ans[i][j]);
			printf("%4d\n",ans[i][n]);}*/
        int sum=0;
        for (int i = 1 ; i <=n ; i++)
            sum= (sum + ans[i][i]) % mod ;
        printf("%d\n" , sum) ;
        }
		
	}
	
}