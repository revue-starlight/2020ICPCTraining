#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a;
    cin>>n>>m>>a;
    int ans1,ans2;
    int tot=n*m;
    if (a%n==0 || a%m==0) {cout<<1<<endl; return 0;}
    else{
        int b=n*m-a;
        for (int i=1;i<=n;i++){
            if ((a-n*i)%(m-i)==0 || (b-n*i)%(m-i)==0   ) {cout<<2<<endl; return 0;}
        }
        for (int i=1;i<=m;i++){
            if ((a-i*m)%(n-i)==0 || (b-n*i)%(m-i)==0 ) {cout<<2<<endl; return 0;}
        }
    }
    //else if ( (a-a/n*n) % (m-a/n)==0 || ((a-a/m*m) % (n-a/m)==0) ) cout<<2<<endl;
    cout<<3<<endl;
}