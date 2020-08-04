#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    while (cin>>T){
        while (T--){
            int n;
            cin>>n;
            int k=n/4;
            if (n%4) k++;
            for (int i=1;i<=n-k;i++){
                cout<<9;
            }
            for (int i=n-k+1;i<=n;i++) cout<<8;
            cout<<endl;
        }
    }
}