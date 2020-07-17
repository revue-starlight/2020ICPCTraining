#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e6+100;
const ll hasi=19270813;
const ll mod=998244353;
ll ans;
map <unsigned long long,int> mp;
string s[maxn];
ll nxt[maxn];
ll res[maxn];
 
inline void kmp(int x){
    nxt[0]=0;
        for(int i=1,j=0;i<s[x].length();i++){
        while(s[x][i]!=s[x][j]&&j) j=nxt[j-1];
        if(s[x][i]==s[x][j]) j++;
        nxt[i]=j;
     }
}

int main(){
    ll n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>s[i];
        unsigned long long x=0,tmp=1;
        for (int j=s[i].length()-1;j>=0;j--){
            x+=tmp*(s[i][j]-'a'+1);
            tmp*=hasi;
            mp[x]++;
        }
    }
    for (int i=1;i<=n;i++){
        unsigned long long x=0,tmp=1;
        for (int j=0;j<s[i].length();j++){
            x=x*hasi+(s[i][j]-'a'+1);
            res[j]=mp[x];
        }
        kmp(i);
        for (int j=0;j<s[i].length();j++){
            if (nxt[j]) res[nxt[j]-1]=res[nxt[j]-1]-res[j];
        }
        for (int j=0;j<s[i].length();j++)
        ans=(ans+res[j]%mod*(j+1)%mod*(j+1)%mod)%mod;
    }
    cout<<ans<<endl;
    
}