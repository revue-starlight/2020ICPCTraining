#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[101];
    int n;
    cin>>n;
    
    memset(a,0,sizeof(a));
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    sort(a+1,a+1+n);
    bool bo[101];
    memset(bo,0,sizeof(bo));
    for (int i=1;i<=n;i++){
        if (bo[i]) continue;
        else {
            bo[i]=true;
            ans++;
            for (int j=i;j<=n;j++){
                if (a[j]%a[i]==0) bo[j]=true;
            }
        }
    }
    cout<<ans<<endl;
}