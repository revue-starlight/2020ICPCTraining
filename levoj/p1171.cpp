#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while (cin>>n){
        if (n==0) continue;
        int a[1000];
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++) {int x; cin>>x; a[x]++;}
        if (n&1) cout<<"Win"<<endl;
        else{
            bool bo=0;
            for (int i=1;i<=100;i++){
                if (a[i]%2!=0){bo=true; break;}
            }
            if (bo) cout<<"Win"<<endl; else cout<<"Lose"<<endl;
        }
    }
}