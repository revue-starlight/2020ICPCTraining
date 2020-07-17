#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int T;
    cin>>T;
    while (T--){
        string s;
        cin>>s;
        int len=s.length();
        // l 1 r 0
        int ans=10000;
        int a[1001];
        memset(a,0,sizeof(a));
        for (int i=0;i<len;i++){
            if (s[i]=='1') a[i]++;
            a[i]=a[i-1]+a[i]; 
        }

        for (int i=0;i<len;i++){
            int num1=0,num2=0;
            for (int j=0;j<=i;j++){
                if (s[i]=='1') num1++;
            }
            for (int j=i+1;j<len;j++){
                if (s[i]=='0') num2++;
            }
            ans=min(ans,i+1-num1+len-i-1-num2);
            ans=min(ans,num1+num2);
        }

        cout<<ans<<endl;

    }
}