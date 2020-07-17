#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int main(){
    string a,b;
    while (cin>>a>>b){
        if (a+b>b+a) {cout<<">"<<endl;}
        else if (a+b==b+a) {cout<<"="<<endl;}
        else cout<<"<"<<endl;
    }
}