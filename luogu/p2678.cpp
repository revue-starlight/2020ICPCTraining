/*
最短跳跃minn， 最长跳跃 l
最多移走x格子
*/
#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
    int l,n,m;
    cin>>l>>n>>m;
    int minn,maxx;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]>maxx) maxx=a[i];
        if (a[i]<minn) minn=a[i];
    }
    int left,right;
    left=minn; right=maxx;
    work(left,right);
}