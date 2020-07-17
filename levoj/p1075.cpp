#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    while (cin>>a>>b){
        
    int res=0,k=0;
        k=1; res=a+b;
    for (int i=2;i<=7;i++){
        cin>>a>>b;
        if (a+b>res) {res=a+b;k=i;}
    }
    if (res<=8) cout<<0<<endl;
    else cout<<k<<endl;
    }
    
}