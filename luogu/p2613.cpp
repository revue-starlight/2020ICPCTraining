#include <iostream>
using namespace std;
#define mod 19260817
inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10%mod+ch-'0'%mod;ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}
int x,y;
void exgcd(int a,int b)
{
    if (b==0) {x=1; y=0; return;}
    exgcd(b,a%b); int p=x; x=y; y=p-a/b*y;
}

int main()
{ 
    int a,b;
    a=read(); b=read();
    if (b==0) {puts("Angry!"); return 0;}
    exgcd(b,mod);
    x=(x%mod+mod)%mod;
    printf("%lld\n",a*(long long)(x)%mod);
    return 0;
}