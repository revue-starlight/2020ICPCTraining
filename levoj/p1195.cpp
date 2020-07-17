#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while (cin>>n){
        int x=1;
        for (int i=2;i<=n;i++){
            x=x+1; x*=2;
        }
        cout<<x<<endl;
    }
}