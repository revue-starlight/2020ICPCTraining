#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
    cin>>T;
    int casee=0;
    while (T--){
        casee++;
        int e,n; string m;
        cin>>e>>n;
        cin>>m;
        int len=m.length();
        int ans=10000;
        for (int i=0;i<len;i++){
            if (i==0 && e==0 && n==0) ans=0;
            int t=i+1;
            if (m[i]=='N') n++;
            else if (m[i]=='E') e++;
            else if (m[i]=='S') n--;
            else if (m[i]=='W') e--;
            int tmpans=INT_MAX;
            if (t>=abs(n)+abs(e))
             tmpans=max((abs(n)+abs(e)),t);
            ans=min(tmpans,ans);
        }
        if (ans<=m.length())
        printf("Case #%d: %d\n",casee,ans);
        else printf("Case #%d: IMPOSSIBLE\n",casee);

    }
}