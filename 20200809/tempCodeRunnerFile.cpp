#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s1;
string s2;

void solve(){
    int n;
    cin>>n;
    cin>>s1>>s2;
    s1+="0";
    s2+="0";
    int ans=0;
    for (int i=0;i<=n;i++){
        if (s1[i]!=s2[i]) ans++;
    }
    int t=0;
    while (s1[t]=='1') {s1[t]='0';t++;}
    s1[t]='1';
    int res=0;
    for (int i=0;i<=n;i++){
        if (s1[i]!=s2[i]) res++;
    }
    cout<<min(ans,res+1)<<endl;
}

int main(){
    int T;
    cin>>T;
    while (T--) solve();
}