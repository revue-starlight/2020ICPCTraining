#include <iostream>
using namespace std;
#define ll long long
#define maxn 500001
ll a[maxn];
ll guibing(int l,int r){
    ll mid=(l+r)>>1;
    ll ans=0;
    if (l>=r) return 0;
    ans+=guibing(l,mid);
    ans+=guibing(mid+1,r);
    int cnt=l;
    int temp[maxn];
    int pointl=l,pointr=mid+1;
    while (cnt<=r){
        if (pointl==mid+1) {while(pointr<=r) temp[cnt++]=a[pointr++]; break;}
        if (pointr==r) {while (pointl<=mid) temp[cnt++]=a[pointl++]; ans+=(r-(mid+1)+1); break;}
        if(a[pointl]<=a[pointr])
         temp[cnt++]=a[pointl++];
        else{        
            ans++;
            temp[cnt++]=a[pointr];
            pointr++;
        }
    }
    for (int i=l;i<=r;i++) a[i]=temp[i];
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin>>n){
        for (int i=0;i<n;i++) cin>>a[i];
        cout<<guibing(0,n-1)<<endl;
        if (n==0) return 0;
    }
}