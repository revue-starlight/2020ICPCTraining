//LCS - 最长公共子序列，是子序列
int LCS(char *s,char *p){
    int lens=s,lenp=p;
    int dp[MAXN][MAXM];
    for (int i=0;i<lens;i++)
        for (int j=0;j<lenp;j++){
            if (s[i]==p[j]) {
                if (i==0 || j==0) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                if (i==0 || j==0) dp[i][j]=0;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[i][j];
}