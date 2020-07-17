#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[41],b[41],ans[41];
    string s1,s2;
    while(cin>>s1>>s2){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(ans,0,sizeof(ans));
    int len1=s1.length(),len2=s2.length();
    for (int i=0;i<len1;i++){
        a[i]=s1[len1-i-1]-'0';
    }
    for (int i=0;i<len2;i++){
        b[i]=s2[len2-i-1]-'0';
    }
    int len=max(len1,len2);
    for (int i=0;i<=len;i++){
        ans[i]+=a[i]+b[i];
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    if (!ans[len]) len--;
    for (int i=len;i>=0;i--) cout<<ans[i];
    cout<<endl;
    }
    
    return 0;
}