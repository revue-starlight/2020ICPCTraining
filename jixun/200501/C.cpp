#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x;
    cin>>n>>m>>x;
    if (x%n==0 || x%m==0) {cout<<1<<endl; return 0;}
    for (int i=1;i<=n;i++){
        if (x>m*i) {
            int k=x-m*i;
            if (k%(n-i)==0) {cout<<2<<endl; return 0;}
        }
        else {
            if (x%i==0) {cout<<2<<endl; return 0;}
        }
    }

    for (int i=1;i<=m;i++){
        if (x>n*i) {
            int k=x-n*i;
            if (k%(m-i)==0) {cout<<2<<endl; return 0;}
        }
        else {
            if (x%i==0) {cout<<2<<endl; return 0;}
        }
    }
    cout<<3<<endl; 
}