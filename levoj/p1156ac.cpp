#include <bits/stdc++.h>
# define LL long long
using namespace std ;

const int MAX = 12 ;
const int MOD = 9973 ;
int n ; //n*n 矩阵

struct Matrix
{
    int mat[MAX][MAX];
};
Matrix mul(Matrix a,Matrix b) //矩阵乘法
{
    Matrix c;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            c.mat[i][j]=0;
            for(int k=0;k<n;k++)
            {
                c.mat[i][j]=(c.mat[i][j] + a.mat[i][k]*b.mat[k][j])%MOD;
            }
        }
    return c;
}
Matrix pow_M(Matrix a,int k)  //矩阵快速幂
{
    Matrix ans;
    memset(ans.mat,0,sizeof(ans.mat));
    for (int i=0;i<n;i++)
        ans.mat[i][i]=1;
    Matrix temp=a;
    while(k)
    {
        if(k&1)ans=mul(ans,temp);
        
     /*   cout<<"k="<<k<<endl;
        for (int i=0;i<n;i++)
        for (int j=0;j<n;j++){
        if (j<n-1) printf("%5d",ans.mat[i][j]);
            else printf("%5d\n",ans.mat[i][j]);
        } */

        temp=mul(temp,temp);
        k>>=1;
    }
    return ans;
}
int main ()
{
    //freopen("in.txt","r",stdin) ;
    int T ;
    scanf("%d" , &T) ;
    while(T--)
    {
        int k ;
        Matrix s ;
        Matrix ans ;
        scanf("%d %d" , &n , &k) ;
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < n ; j++)
                scanf("%d" , &s.mat[i][j]) ;
        ans = pow_M(s,k) ;
        int sum = 0 ;
        for (int i = 0 ; i < n ; i++)
            sum= (sum + ans.mat[i][i]) % MOD ;
        printf("%d\n" , sum) ;

    }

    return 0 ;
}