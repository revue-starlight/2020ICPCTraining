#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while (T--){
    int n;
    string s;
    cin>>n>>s;
    int cnt=0;
    while (!s.empty() && s[0]==s.back()){
        cnt++;
        s.pop_back(); 
    }
    if (s.empty()){
        cout<<(cnt+2)/3<<"\n";
        continue;
    }
    s.push_back('$');
    int ans=0;
    for (int i=0;i+1<s.size();i++){
        cnt++;
        if (s[i]!=s[i+1]){
            ans+=cnt/3;
            cnt=0;
        }
    }
    cout<<ans<<"\n";
    }
}