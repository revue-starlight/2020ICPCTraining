#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int T;
    cin>>T;
    int n,a[1000];
    while (T--){
        cin>>n;
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++){
            int k;
            cin>>a[i];
            if (i%2){
                if (a[i]>=0) a[i]=-a[i];  
            }
            else
                a[i]=abs(a[i]);
        }
        for (int i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
}