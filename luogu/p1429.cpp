#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
    int x,y;
};
int tmp1[1000],tmp2[1000];
node a[10000];

double dist(int i,int j)
{
    int x=a[i].x-a[j].x;
    int y=a[i].y-a[j].y;
    return(sqrt(x*x+y*y));
}

double work(int l,int r)
{
    if (l==r) return 99999;
    else if (l==r-1) return dist(l,r);
    else
    {
        int mid=l+r>>1;
        int t1=0,t2=0;
        double d=min(work(l,mid),work(mid+1,r));
        for (int i=mid;i>=l;i--)
        {
            if (a[mid].y-a[i].y<d)
            tmp1[++t1]=i;
            else break;
        }
        for (int i=mid+1;i<=r;i++)
        {
            if (a[i].y-a[mid].y<d)
            tmp2[++t2]=i;
            else break;
        }
        // t1 存左，t2存右
        int ans=INT_MAX;
        for (int i=1;i<=t1;i++)
            for (int j=1;j<=t2;j++)
                if (ans>dist(tmp1[i],tmp2[j])) ans=dist(tmp1[i],tmp2[j]);
        return ans;
    }
    
    
}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    
    cout<<work(1,n)<<endl;
}