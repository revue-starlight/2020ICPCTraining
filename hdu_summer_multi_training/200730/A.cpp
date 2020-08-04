#include <bits/stdc++.h>
using namespace std;
int a[100][2];
int main(){
    int n;
    cin>>n;
    a[1][0]=1;
    a[1][1]=0;
    for (int i=2;i<=n;i++){
        a[i][0]=a[i-1][0]+a[i-1][1];
        a[i][1]=a[i-1][0];
    }
    for (int i=1;i<=n;i++){
        cout<<i<<" "<<a[i][0]+a[i][1]<<endl;
    }

}