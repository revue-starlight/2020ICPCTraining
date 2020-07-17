#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int main(){
    cin>>n;
    char ch;
    ll ans=0;
    int youxu=0;
    int zuo=0,you=0;
    if (n%2==1) {cout<<"No"<<endl; return 0;}
    for (int i=1;i<=n;i++){
        cin>>ch;
        if (ch=='(') ans++;
        if (ans>0 && ch==')') {ans--; youxu+=2;}
        if (ch=='(') {zuo++;}
        if (ch==')') {you++;}
    }
    if (n-youxu<=2 && zuo==you) cout<<"Yes"; else cout<<"No";

}