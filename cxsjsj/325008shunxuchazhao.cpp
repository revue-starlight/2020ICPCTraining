#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[]={11,35,13,63,5};
    int x;
    cin>>x;
    for (int i=0;i<5;i++){
        if (a[i]==x) {cout<<i<<endl; return 0;}
    }
    cout<<"failed"<<endl;
    return 0;
}