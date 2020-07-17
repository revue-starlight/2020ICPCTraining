#include <bits/stdc++.h>
using namespace std;
int a[100];
int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++)  cin>>a[i];
        sort(a+1,a+1+n);
        int ans=INT_MAX;
        for (int i=2;i<=n;i++){
            if (a[i]-a[i-1]<ans) ans=a[i]-a[i-1];
        }
        cout<<ans<<endl;
    }
}