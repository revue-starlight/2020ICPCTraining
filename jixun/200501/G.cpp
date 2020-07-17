#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a[100];
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int minn=1000,d=-1;
    for (int i=0;i<=n-3;i++){
        if (max(a[i],a[i+2])<minn) {minn=max(a[i],a[i+2]); d=i;}
    }
    cout<<d+1<<" "<<minn<<endl;
    return 0;
}