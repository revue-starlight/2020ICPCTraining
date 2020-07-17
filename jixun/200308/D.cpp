#include <bits/stdc++.h>
using namespace std;
#define maxn 5001
int k,n,s,a[maxn];
int dp[maxn][maxn]; //前i个数字，sum=maxn的最小操作数
int qian_mian_zui_hao_de[maxn][maxn];//把i改成v要多少个操作（i<=k)
int m[5001][5001];
vector <int> vec[5001];
int main(){



    scanf("%d%d%d",&n,&k,&s);
     for (int i=0;i<n;i++){
        scanf("%d",a+i);
        if (!m[i%k][a[i]]) vec[i%k].push_back(a[i]);//vec[第i个数字]里面出现了哪些数字
        m[i%k][a[i]]++;//第i个数字里各个数字出现的个数
    }
    int p;
    if (n%k) p=(n/k)+1; else p=n/k;
    //一共有p组

    int minn=0;

    for (int j=0;j<=s;j++) {dp[0][j]=m[0][j]; 
            qian_mian_zui_hao_de[0][j]=max(dp[0][j],qian_mian_zui_hao_de[0][j-1]);}
    

    for (int i=1;i<k;i++){
        for (int j=0;j<=s;j++)
        {
            dp[i][j]=qian_mian_zui_hao_de[i-1][j];
            int len=vec[i].size();
            for (int v=0;v<len;v++){
                if (vec[i][v]<=j)
                dp[i][j]=max(dp[i-1][j-vec[i][v]]+m[i][vec[i][v]],dp[i][j]);
            }
            if (j==0) qian_mian_zui_hao_de[i][j]=dp[i][j];
            else
            qian_mian_zui_hao_de[i][j]=max(dp[i][j],qian_mian_zui_hao_de[i][j-1]);
        }
    }

    cout<<n-dp[k-1][s]<<endl;
}