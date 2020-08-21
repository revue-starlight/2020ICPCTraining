// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int maxn=2e5+20;
int mp[maxn][26];
inline void solve(){
    int n,k;
    string s;
    cin>>n>>k>>s;
    for (int i=0;i<=n;i++){
        for (int j=0;j<26;j++) mp[i][j]=0;
    }
    for (int i=0;i<k/2;i++){
        for (int x=0;x<n/k;x++){
            int pos=i+x*k;
            int pos2=(x+1)*k-i-1;
            mp[i][s[pos]-'a']++;
            mp[i][s[pos2]-'a']++;
        }
    }
    int ans=0;
    for (int i=0;i<k/2;i++){
        int tmp=0x3f3f3f3f;
        for (int j=0;j<26;j++){
            tmp=min(tmp,2*n/k-mp[i][j]);
        }
        ans+=tmp;
    }
    if (k%2){
        for (int x=0;x<n/k;x++)
        {
            int pos=x*k+(k/2);
            mp[k/2][s[pos]-'a']++;
        }
        int tmp=0x3f3f3f3f;
        for (int j=0;j<26;j++){
            tmp=min(tmp,n/k-mp[k/2][j]);
        }
        ans+=tmp;
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while (T--) solve();
    return 0;
}