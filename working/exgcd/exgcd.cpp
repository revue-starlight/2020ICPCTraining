/* 99x+78y=3 */
#include <bits/stdc++.h>
using namespace std;
int d,x,y;
void exgcd(int a,int b)
{
    if (b==0)
    {d=a; x=1; y=0; return;}
    else {exgcd(b,a%b); int tx=x; x=y; y=tx-(a/b)*y;}
}

int main()
{
    exgcd(99,78);
    cout<<x<<" "<<y;
    /*ax+by=S Smin(s>0)=gcd(a,b);
     计算x,y的正整数解，顺便求成立的最小的S。
    */
}