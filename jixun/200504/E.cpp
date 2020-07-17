#include <bits/stdc++.h>
using namespace std;
map <string,int> mp;
int dp[10001];
struct item{
    int cost,value;
};
int a[1000001];

int main(){
    int B,n,tot;
    cin>>B>>n;
    tot=0;
    for (int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        if (!mp[s1]) mp[s1]=tot++;
        if (!mp[s2]) mp[s2]=tot++;
        
    }
}