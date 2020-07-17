#include <bits/stdc++.h>
using namespace std;
int fib[10000];
double ans;
int main(){
    int n;
    while (cin>>n) {
    fib[1]=1;
    fib[2]=2;
    ans=0;
    for (int i=3;i<=n+1;i++)
    fib[i]=fib[i-1]+fib[i-2];
    for (int i=1;i<=n;i++){
        double k=(double)(fib[i+1])/(double)(fib[i]);
        if (!(i%2)) k=-k;
        ans+=k;
    }
    printf("%.4lf\n",ans);
    }
}