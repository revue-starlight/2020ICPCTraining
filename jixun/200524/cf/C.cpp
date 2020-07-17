#include <bits/stdc++.h>
using namespace std;
int a[100];
bool b[100];
int main(){
    int t;
    cin>>t;
    while (t--){
        memset(b,0,sizeof(b));
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        int xiangling=0;
        for (int i=1;i<=n-1;i++){
            if (b[i]) continue;
            if (a[i]+1==a[i+1]){
                b[i]=b[i+1]=1;
                xiangling++;
            }
        }
        int dan=0,shuang=0;
        for (int i=1;i<=n;i++){
            if (b[i]) continue;
            if (a[i]%2) dan++;
            else shuang++;
        }
        if ((dan%2==0 && shuang%2==0)) {cout<<"YES"<<endl;}
        else if ((dan%2==1 && shuang%2==1) && xiangling>=1) {cout<<"YES"<<endl; }
        else cout<<"NO"<<endl;
    }
}