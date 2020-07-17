#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T;
int main(){
    cin>>T;
    while (T--){
        int n,x;
        int xx;
        cin>>n>>x;
        int ji=0,ou=0;
        for (int i=1;i<=n;i++) {cin>>xx; if (xx%2==0) ou++; else ji++;}
        bool bo=true;
        for (int k=1;k<=x;k=k+2){
            if (k<=ji && x-k<=ou) {
                cout<<"Yes"<<endl;
                bo=false;  break;
            }

        }
        if (bo) cout<<"No"<<endl;
    }
    
}