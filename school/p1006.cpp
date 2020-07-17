#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
 if (b==0) return a;
else return gcd(b,a%b);
}

int main(){
    int a,b,n;
    while (cin>>n){
    for (int i=1;i<=n;i++)
    {cin>>a>>b;
    cout<<a*b/gcd(a,b)<<endl;
    }
    }
return 0;
}