#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=10;
    int a[10];
    for (int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    sort(a,a+10);
    for (int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    int x;
    cin>>x;
    int l=0,r=9;
    while (l<r){
        int mid=(l+r)>>1;
        if (a[mid]==x) {cout<<mid<<endl;return 0;}
        if (a[mid]<x) l=mid+1; else r=mid-1;
    }
}