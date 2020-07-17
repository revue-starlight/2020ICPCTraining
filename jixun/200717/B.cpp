#include <bits/stdc++.h>
using namespace std;
long long m[11];
long long a[11];
int main(){
    for (int i=1;i<=10;i++){
        m[i]=pow(2,i)-1;
    }
    for (int i=1;i<=10;i++){
        a[i]=i;
    }
    long long  n;
    long long ans=1;
    cin>>n;
    for (int i=1;i<=n;i++){
        char ch;
        int x;
        cin>>ch>>x;
        if (ch=='S') ans=max(a[x],ans);
        else ans=max(m[x],ans);
    }
    cout<<ans<<endl;
    return 0;
}