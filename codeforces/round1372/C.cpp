#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        int a[maxn];
        int s,t;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        a[0]=0; a[n+1]=n+1;
        s=0; t=n+1;
        while (a[s]==s && s<=n) s++;
        while (a[t]==t && t>0) t--;
        if (s==n+1) {cout<<"0\n"; continue;}
        bool bo2=false;
        for (int i=s+1;i<t;i++) if(a[i]==i) {bo2=true; break;}
        if (bo2) cout<<2<<endl;
        else cout<<1<<endl;
    }
}