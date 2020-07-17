#include <bits/stdc++.h>
using namespace std;
int main(){
    int s1,s2;
    int n;
    while (cin>>n){
        
    s1=7,s2=11;
        if (n==0) cout<<"no"<<endl;
        else if (n==1) cout<<"no"<<endl;
        else {
            for (int i=2;i<=n;i++){
            int tmp=s1;
            s1=s2;
            s2=tmp+s2;
            s2=s2%3;
            s1=s1%3;
        }
        if (s2%3==0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
        }
    }
}