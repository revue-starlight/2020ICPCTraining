#include <bits/stdc++.h>
#define maxn 200005
int ans[maxn];
int a[maxn];
using namespace std;
int main(){
    int n;
    int t;
    cin>>t;
    while (t--){
    cin>>n;
    bool bo=true;
    for (int i=1;i<=n;i++) {char ch; cin>>ch; a[i]=ch-'0';}
    for (int i=0;i<=9;i++){
        bo=true;
        for (int p=1;p<=n;p++) ans[p]=0;
        int k=i;
        int j=n;
        while (a[j]!=k) j--;
        for (j;j>=1;j--){
            if (a[j]>k) continue;
            ans[j]=1;
            k=a[j];
        }
        k=i;
        for (int j=1;j<=n;j++){
            if (ans[j]==1) continue;
            if (a[j]<k) {bo=false; break;}
            k=a[j];
        }
        if (bo){
            for (int j=1;j<=n;j++){
                if (ans[j]==1) cout<<"1"; else cout<<"2";
            }
            cout<<endl;
            break;
        }
    }
    if(!bo) cout<<'-'<<endl;
    }
}