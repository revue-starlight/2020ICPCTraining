#include <bits/stdc++.h>
using namespace std;
#define maxn 81
int a[maxn][maxn];
int main(){
    int n;
    while (cin>>n){
        for (int i=1;i<=n;i++)//不野蛮
            for (int j=1;j<=n;j++) cin>>a[i][j];
        for (int j=1;j<=n;j++)
            for (int i=1;i<=n;i++)
                a[i][j]+=a[i-1][j];
        
        int maxx=-0x3f3f3f3f;
        for (int xlhs=1;xlhs<=n;xlhs++)
        {//xlhs==相邻的行数
            for (int qsh=1;qsh<=n-xlhs+1;qsh++){
                int dp[maxn];
                int tmax=-0x3f3f3f3f;
                memset(dp,0,sizeof(dp));
                //qsh==起始行 [qsh,qsh+xlsh-1]
                //累加取变量名用啥的来着？我摸了鱼全忘了
                int leijia=0;
                int jwh=qsh+xlhs-1;
                
                for (int i=1;i<=n;i++){
                    dp[i]=a[jwh][i]-a[qsh-1][i];
                    if (leijia+dp[i]>tmax && leijia+dp[i]>tmax+leijia+dp[i]) {tmax=leijia+dp[i]; leijia=0; }       
                    else if (tmax+leijia+dp[i]>tmax) {tmax=tmax+leijia+dp[i]; leijia=0;}
                    else leijia+=dp[i];
                    
                }

                if (maxx<tmax) maxx=tmax;
                
            }
        }
        
        cout<<maxx<<endl;
    }
}
