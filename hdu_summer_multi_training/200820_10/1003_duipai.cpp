#include <bits/stdc++.h>
using namespace std;
int solve(){
    
    int a,b;
    string s[30];
    int ans=0;
    cin>>a>>b;
    for (int i=0;i<a;i++) cin>>s[i];
    for (int i=0;i<a;i++)
        for (int j=0;j<b;j++)
             if (s[i][j]=='.'){
                if (i-1>=0 && j-1>=0 && s[i-1][j-1]=='X') ans++;
                if (i-1>=0 && s[i-1][j]=='X') ans++;
                if (i-1>=0 && j+1<b && s[i-1][j+1]=='X') ans++;
                if (j-1>=0 && s[i][j-1]=='X') ans++;
                if (j+1<b && s[i][j+1]=='X') ans++;
                if (i+1<a && j-1>=0 && s[i+1][j-1]=='X') ans++;
                if (i+1<a && s[i+1][j]=='X') ans++;
                if (i+1<a && j+1<b && s[i+1][j+1]=='X') ans++;
            }
        return ans;
}
int main(){
    
freopen("1.in","r",stdin);
    int T;
    cin>>T;
    while (T--){
        cout<<"T:"<<1000-T<<" ";
        int ans;
        cin>>ans;
        int q=solve();
        if (ans==q) cout<<"Yes\n"; else cout<<q<<" NO\n";
    }
    return 0;
}