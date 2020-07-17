#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char ch;
    int a[100];
    memset(a,0,sizeof(a));
    int minn=-1;
    if (n==1) {cout<<"Yes"<<endl; return 0;}
    for (int i=1;i<=n;i++){
        cin>>ch;
        a[ch-'a']++;
        minn=max(minn,a[ch-'a']);
    }
    if (minn>=2) cout<<"Yes"<<endl; else cout<<"No"<<endl;
}