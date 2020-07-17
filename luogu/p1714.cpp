#include <bits/stdc++.h>
using namespace std;
long long a[10005];
node q[10005];
long long ans=-1;
long long front,back;
struct node{
    long long x,i;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin<<a[i];
        a[i]+=a[i-1];
    }
    for (int i=1;i<=n;i++)
    {
        while (q[front].i<i-k) front++;
        ans=max(ans,a[i]-q[front].x);
        if (i-k==q[front].i) front++;
        while (q[back].x>=a[i] && front>back) back--;
        node tmp2; tmp2.x=a[i]; tmp2.i=i;
        q[back]=tmp2;
    }
    cout<<ans;
    return 0;
}