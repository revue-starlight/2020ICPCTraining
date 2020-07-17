#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        double a=abs(m-n);
        double b=(sqrt(5)+1)/2.0;
        if ((int)(a*b)==min(n,m)) cout<<0<<endl;
        else cout<<1<<endl;
    }
}