#include <bits/stdc++.h>
using namespace std;
#define ll long long
char s1[100004],s2[100004];
void solve(){
    int n;
    cin>>n;
    getchar();
    for (int i=0;i<n;i++) s1[i]=getchar(); getchar();
    for (int i=0;i<n;i++) s2[i]=getchar();
    s1[n]='0';
    s2[n]='0';

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