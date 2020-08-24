#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int a[N],b[N];
bool cmp(int x,int y){
    if (a[x]==a[y]) return x<y; else return a[x]>a[y];
}
int main(){
    int T;
    cin>>T;
    while (T--){
        int n,m,k; cin>>n>>m>>k;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++) b[i]=i;
        if (k==0) {for (int i=1;i<n;i++) cout<<i<<" "; cout<<n<<"\n"; continue;}
        sort(b+1,b+1+n,cmp);
        for (int i=1;i<n;i++) cout<<b[i]<<" "; cout<<b[n]<<"\n";
    }
}