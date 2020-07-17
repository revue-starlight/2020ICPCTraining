#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[2],d;
    cin>>a[0]>>a[1]>>d;
    while (d--){
        if (a[0]>a[1]) a[0]/=2;
        else a[1]/=2;
    }
    sort(a,a+2);
    cout<<a[1]<<" "<<a[0];
    return 0;
}