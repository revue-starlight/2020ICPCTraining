#include <bits/stdc++.h>
using namespace std;
int a[]={1,1,1,1,1,1,1,1,3,3,3,3};
int main(){
   // cout<<a.begin()<<" "<<a.end()<<endl;
    cout<<unique(a,a+12)-a<<endl;
    for (int i=0;i<12;i++) cout<<a[i]<<" ";
}