#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 201
struct node1{
    int id,val;
    bool operator<(const node1& a) const{
         return val < a.val; //大顶堆
     }
};
struct node2{
    int id,val;
    bool operator<(const node2& a) const{
         return val > a.val; //小顶堆
     }
};
ll a[maxn],sum[maxn];
int main(){
   ll n,k;
   cin>>n>>k;
   ll maxx=-0x3f3f3f3f;
   for (int i=1;i<=n;i++) {cin>>a[i]; sum[i]=sum[i-1]+a[i];}

   for (int i=1;i<=n;i++)
    for (int j=i;j<=n;j++){
        ll sum_seg=sum[j]-sum[i-1];
        priority_queue <node1> out;
        priority_queue <node2> in;
        for (int tmp=1;tmp<i;tmp++) {node1 x; x.id=tmp; x.val=a[tmp]; out.push(x);}
        for (int tmp=i;tmp<=j;tmp++) {node2 x; x.id=tmp; x.val=a[tmp]; in.push(x);}
        for (int tmp=j+1;tmp<=n;tmp++) {node1 x; x.id=tmp; x.val=a[tmp]; out.push(x);}
        maxx=max(sum_seg,maxx);
        for (int tmp2=1;tmp2<=k;tmp2++){
            if (!out.empty() && !in.empty()){
                node1 x; x=out.top();
                node2 y; y=in.top();
                in.pop(); out.pop();
                sum_seg=sum_seg+x.val-y.val;
                maxx=max(sum_seg,maxx);
            }
        }
        while (!out.empty()) out.pop();
        while (!in.empty()) in.pop();
    }
    cout<<maxx<<endl;
    return 0;
}