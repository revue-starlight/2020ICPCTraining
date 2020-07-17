#include <bits/stdc++.h>
using namespace std;
int a[500];
int main(){
    int n,m;
    while (cin>>n>>m){
        int k=n+m;
        for (int i=1;i<=k;i++) cin>>a[i];
        sort(a+1,a+1+k);
        for (int i=1;i<=k;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
}