#include <bits/stdc++.h>
using namespace std;
string s;
map <long long ,int> m;
int main(){
    int n;
    cin>>n;
    cin>>s;
    int len=s.length();
    long long zhuang_ya_zhi=0;
    int ans;
    for (int i=0;i<len;i++){
        zhuang_ya_zhi=zhuang_ya_zhi^(1<<(s[i]-'a'));
        if (zhuang_ya_zhi==0) ans=max(ans,i+1);
        else
        {
            for (int j=0;j<20;j++) {
                int tmp=zhuang_ya_zhi^(1<<j);
                if  (tmp==0)
                    ans=max(ans,i+1);
            }

            if (m[zhuang_ya_zhi]) ans=max(ans,i-m[zhuang_ya_zhi]);
                else m[zhuang_ya_zhi]=i;
        }
        
    }
    cout<<ans<<endl;
}