#include <bits/stdc++.h>
using namespace std;
string sx[20001];
const long long mod=998244353;

int main(){
    string s;
    cin>>s;
    int len=s.length();
    sx[0]=s[0];
    for (int i=1;i<len;i++){
        sx[i]=sx[i-1]+s[i];
    }
    sort(sx,sx+len,cmp);
    /*for (int i=0;i<len;i++) cout<<sx[i]<<" ";
    cout<<endl;*/
    string anss;
    for (int i=0;i<len;i++) {anss=anss+sx[i];}
    //cout<<anss<<endl;
    len=anss.length();
    long long ans=0;
    for (int i=0;i<len;i++){
        long long x=anss[i]-'0';
        ans=(ans*10+x)%mod;
    }
    cout<<ans;
}