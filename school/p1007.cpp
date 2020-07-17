#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,n;
    while (cin>>n){
    for (int i=1;i<=n;i++)
    {cin>>a;
    int cnt=0;
    while (a){
        if (a%2) cnt++;
        a/=2;
    }
    cout<<cnt<<endl;
    }
    }
return 0;
}