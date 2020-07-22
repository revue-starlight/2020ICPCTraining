#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        if (n==1) cout<<26<<endl;
        else if (n==2) cout<<26*26<<endl;
        else if (n==3) cout<<26*26*26<<endl;
        else {
            cout<<26*25*24<<endl;
        }
    }
}