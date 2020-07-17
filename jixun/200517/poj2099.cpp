#include <iostream>
using namespace std;
#define ll long long
#define maxn 500001
ll a[maxn],temp[maxn],f[maxn];
int ans=0;
void he(int st,int end,int mid){
    int l=st,r=mid+1;
    for(int i=st;i<=end;i++){
        if(l<=mid&&(r>end||a[l]<=a[r])){
            temp[i]=f[l]; l++;
        }
        else{
            temp[i]=a[r]; r++;
            ans+=mid-l+1;
        }
    }
    for(int i=st;i<=end;i++)a[i]=temp[i];
}
void my_msort(int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        my_msort(l,mid);
        my_msort(mid+1,r);
        he(l,r,mid);
    }
}
int main(){

    int n;
    while (scanf("%d",&n)){
        ans=0;
        for (int i=0;i<n;i++) scanf("%d",a+i);
        my_msort(0,n-1);
        cout<<ans<<endl;
        if (n==0) return 0;
    }
}