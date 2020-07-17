#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        int ans=0,cnt=0;
        for (int i=1;i<=n;i++){
            cnt++;
            if (a[i]==cnt) {ans++; cnt=0;}
        }
        cout<<ans<<endl;
    }
}