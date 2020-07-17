#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,n;
    while (cin>>n){
        while (n--){
        cin>>a>>b;
        cout<<a*b/__gcd(a,b)<<endl;}
    }
}