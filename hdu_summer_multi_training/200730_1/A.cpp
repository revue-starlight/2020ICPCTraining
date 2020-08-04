#include <bits/stdc++.h>
using namespace std;
map <int,int> mp;
const int a[]={6,10,14,15,21,22};
int main(){
    int T;
    int a,b,c,d;
    while (cin>>T){
        while (T--){
            int x;
            cin>>x;
            if (x<=30) cout<<"NO"<<endl;
            else{
                cout<<"YES"<<endl;
                if (x==36 || x==40 || x==44) cout<<"6 10 15 "<<x-6-10-15<<endl;
                else cout<<"6 10 14 "<<x-6-14-10<<endl;
            }
        }
    }
}