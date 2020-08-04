#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
map <int,int> mp;
int ans=0;
int n,p,m;
int sum=0;
int a[N];
int bucket[N];
int main(){
    int T;
    cin>>T;
    while (T--){
        ans=0;
        mp.clear();
        cin>>n>>p;
        for (int i=1;i<=n;i++){
           cin>>a[i];
           a[i]+=a[i-1];
           a[i]%=p;
           if (mp[a[i]]  || a[i]==0) {ans++; mp.clear(); a[i]=0;}
           else 
           mp[a[i]]=1;

        }
        cout<<ans<<endl; 
    }

}