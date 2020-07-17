#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
using namespace std;
ll n;
struct node{
    ll x,y,num;
}a[maxn];

int cmp(node a,node b){
    if (a.x==b.x) return a.y<b.y;
    else return a.x<b.x;}

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++){cin>>a[i].x>>a[i].y; a[i].num=i;}
    sort(a+1,a+n+1,cmp);
    ll x=3;
    while(1){
        ll x1=a[1].x-a[2].x,y1=a[1].y-a[2].y,x2=a[x].x-a[1].x,y2=a[x].y-a[1].y;
         if((x1*y2-x2*y1)!=0) break; else x++;
    }
    cout<<a[1].num<<" "<<a[2].num<<" "<<a[x].num<<endl;
    return 0;
}