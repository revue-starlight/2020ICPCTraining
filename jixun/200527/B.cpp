#include <bits/stdc++.h>
using namespace std;
int aa[101][10001];
char ch[101];
int a[101];
int b[101];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>ch[i];
        if (ch[i]=='1') aa[i][0]=1; else aa[i][0]=0;
    }
    for (int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        int t=1;
        for (t=1;t<b[i];t++) aa[i][t]=aa[i][0];
        for (t;t<a[i]+b[i];t++) aa[i][t]=1-aa[i][0];
        for (t;t<10000;t++) aa[i][t]=1-aa[i][t-a[i]];
    }
    int tmp=0;
    for (int t=0;t<=10000;t++){
        tmp=0;
        for (int i=1;i<=n;i++) {
            if (aa[i][t]==1) tmp++;
        }
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
}