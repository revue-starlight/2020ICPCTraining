#include <bits/stdc++.h>
using namespace std;
void exgcd(int a,int b,int &x,int &y)
{
    if (b==0) {x=1; y=0;} 
    else {
        exgcd(b,a%b,x,y);
        int tx=x;
        x=y;
        y=tx-(a/b)*y;
        return;
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    int x=0,y=0;
    exgcd(a,b,x,y);
    cout<<(x+b)%b;
    return 0;
}