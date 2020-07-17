#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a[2001];
    int cnt[2001];
    map <int,int> mp;
    memset(a,0,sizeof(a));
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    int l;
    for (int i=0;i<n;i++){
        if (mp[a[i]]!=0) break;
        mp[a[i]]++;
        l=i;
        if (i==n-1) {cout<<n<<endl; return 0;}
    }
    
    map <int,int> mp2;
    int r=n-1;
    int ans=n-1-l;
    for (int i=n-1;i>=0;i--){
        if (mp2[a[i]]!=0) break;
        mp2[a[i]]++;
        r=i;
        if (mp[a[i]]!=0){
        while (a[l]!=a[i] && l>=0) {mp[a[l]]=0; l--;}
        mp[a[l]]=0; l--;}
        if (ans>r-1-l) ans=r-1-l;
    }
    cout<<ans;
}