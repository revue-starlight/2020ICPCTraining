#include <bits/stdc++.h>
using namespace std;
#define maxn 1000001
int main(){
    int n;
    int a,b,c;
    cin>>n;
    cin>>a>>b>>c;
    int ans=0;
    for (int i=1;i<=n;i++){
        if (i%a!=0 && i%b!=0 && i%c!=0) ans++;
    }
    cout<<ans;
    return 0;
}