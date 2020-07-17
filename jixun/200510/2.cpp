#include <bits/stdc++.h>
using namespace std;
map <string,int> mp;
int main(){
    int n;
    cin>>n;
    int all=0;
    int ans=0;
    string ans_t;
    bool bo=true;
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]++;
        all++;
        if (mp[s]>ans) {ans=mp[s]; ans_t=s;}
    }
    if (ans<=all-ans) cout<<"NONE"; else cout<<ans_t;
}