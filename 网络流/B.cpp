#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define Times 11
#define inf ((long long)1<<61)
#define C 201
long long c,e,n;
long long jl[501],mini=inf;//jl里面存的是大数的所有质因子，mini为最小的质因数
int ct;
long long gcd(long long a,long long b)//最大公约数
{
    return b==0?a:gcd(b,a%b);
}
long long random(long long n)//生成随机数
{
 return (long long)((double)rand()/RAND_MAX*n+0.5);
}
long long multi(long long a,long long b,long long m)//a*b%m
{
    long long ret=0;
    while(b>0)
    {
        if(b&1)ret=(ret+a)%m;
        b>>=1;
        a=(a<<1)%m;
    }
    return ret;
}
long long quick_mod(long long a,long long b,long long m)//a^b%m
{
    long long ans=1;
    a%=m;
    while(b)
    {
        if(b&1)
        {
            ans=multi(ans,a,m);
            b--;
        }
        b/=2;
        a=multi(a,a,m);
    }
    return ans;
}
 
long long pollard_rho(long long n)
{
    long long x,y,d,i=1,k=2;
    x=random(n-1)+1;
    y=x;
    while(1)
    {
        i++;
        x=(multi(x,x,n)+c)%n;
        d=gcd(y-x,n);
        if(1<d&&d<n)return d;
        if(y==x)return n;
        if(i==k)
        {
            y=x;
            k<<=1;
        }
    }
}
 
long long exgcd(long long A,long long &x,long long B,long long &y)
{
    long long x1,y1,x0,y0;
    x0=1;y0=0;
    x1=0;y1=1;
    long long r=(A%B+B)%B;
    long long q=(A-r)/B;
    x=0;y=1;
    while(r)
    {
        x=x0-q*x1;
        y=y0-q*y1;
        x0=x1;
        y0=y1;
        x1=x;y1=y;
        A=B;B=r;r=A%B;
        q=(A-r)/B;
    }
    return B;
}
int main()
{
    while(scanf("%I64d%I64d%I64d",&c,&e,&n)!=EOF)
    {
        ct=0;
        long long p=pollard_rho(n);
        long long q=n/p;
        long long tt=(p-1)*(q-1);
        long long x,y;
        long long d=exgcd(e,x,tt,y);
        x=(x%(tt/d)+tt/d)%(tt/d);
        printf("%I64d\n",quick_mod(c,x,n));
    }
    return 0;
}