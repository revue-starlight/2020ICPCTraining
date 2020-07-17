
#include<stdio.h>
#include<string.h>
int n,p[100]={1,1},a[50],b[20];   //数组a用来存数据，数组b用来标记数字是否被使用
void sushu()  //p数组用来标记素数，若不是素数就标记为1
{
    for(int i=2;i<=10;i++)
     if(p[i]==0)
        for(int j=2*i;j<=40;j+=i)
         p[j]=1;
}
void dfs(int s)
{
    if(s==n+1&&p[a[1]+a[n]]==0)  //如果环成立就输出
    {
        for(int i=1;i<n;i++)
          printf("%d ",a[i]);
          printf("%d\n",a[n]);
        return ;
    }
    for(int i=2;i<=n;i++)
    {
        if(b[i]==0&&p[i+a[s-1]]==0)
        {
            a[s]=i;
            b[i]=1;
            dfs(s+1);
            b[i]=0;
        }
    }
    return ;
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data2.out","w",stdout);
    int t=1; 
    sushu();
    a[1]=1;
    while(~scanf("%d",&n))
    {
        memset(b,0,sizeof(b));
        printf("Case %d:\n",t++);
        if(n%2==0||n==1) 
           dfs(2);
            printf("\n");
    }
    return 0;
}