#include <bits/stdc++.h>
using namespace std;
int a[1001];
int b[1001];
bool cmp(int x,int y){
    return a[x]>a[y];
}
int cnt=0;
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n; cnt=0;
        
        for (int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=i;
            if (a[i]==0) cnt++;
        }
            sort(b+1,b+n+1,cmp);
        if (cnt<n-2) {cout<<"namo"<<endl; continue;}
        if (cnt==n) {cout<<"namo"<<endl; continue;}
        if (cnt==n-1) {cout<<b[1]<<endl; continue;}
        
        if (a[b[2]]>1) cout<<"namo"<<endl;
            else{
                if (b[1]>b[2]) cout<<"namo"<<endl;
                else cout<<b[1]<<endl;
            }
        }
    return 0;
}