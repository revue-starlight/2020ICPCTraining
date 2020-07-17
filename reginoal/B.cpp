#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    ll ans=0;
    while (cin>>s){
        int len=s.length();
        int res=0;
        for (int i=0;i<len;i++)
            if (s[i]=='|') res++;
        if (res==len) {ans=ans+res*42; continue;}

        int p=0;
        int k=0;
        while (s[p]>='0' && s[p]<='9'){
            k=k*10+s[p]-48;
            p++;
        }
        ans=ans+k*res;
    }
   // cout<<ans<<endl;
    if (ans%10) cout<<ans/10*10+10<<",-"<<endl; else cout<<ans<<",-"<<endl;
}