#include <bits/stdc++.h>
using namespace std;
int n,a[200002];
int succ[200000];

int work(int l,int r,int mid)
{
    if (l==r) return a[l]-a[l-1];
    int ans1=-210000,ans2=-210010;
    for (int i=mid;i>=1;i--)
    ans1=max(ans1,a[mid]-a[i-1]);
    for (int j=mid+1;j<=n;j++)
    ans2=max(ans2,a[j]-a[mid]);
    int ans=ans1+ans2;
    return max(ans,max(work(l,(l+mid)/2,mid),work(mid+1,(mid+1+r)/2,r)));
    
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    cout<<work(1,(1+n)/2,n);
           
}