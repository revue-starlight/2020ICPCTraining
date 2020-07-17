#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a;
    cin>>n>>m>>a;
    //if (n*m-a>a) a=n*m-a;
    if (a%n==0 || a%m==0) cout<<1<<endl;
    for (int i=1;i<=m;i++){
        int k=a-i*n;
        if (k%i==0 || k%(m-i)==0) {cout<<2<<endl; return 0;}
    }
    for (int i=1;i<=n;i++){
        int k=a-i*m;
        if (k%i==0 || k%(n-i)==0) {cout<<2<<endl; return 0;}
    }
    cout<<3<<endl;
}