#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001
struct node{
    long long val,point,pconst;
    bool operator<(const node& a) const
    {
        return val > a.val; //大顶堆
    }
};
priority_queue <node> q;
int n;
long long a[MAXN],b[MAXN];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%ld",&a[i]);
    for (int i=1;i<=n;i++) scanf("%ld",&b[i]);
    int sum=0;
    for (int i=1;i<=n;i++){
        node tmp;
        tmp.point=1;
        tmp.pconst=i;
        tmp.val=a[1]+b[i];
        q.push(tmp);}
    while (sum<n){
        sum++;
        node tmp=q.top();
        printf("%d ",tmp.val);
        q.pop();
        tmp.val=a[++tmp.point]+b[tmp.pconst];
        if (tmp.point<=n) q.push(tmp);
    }
    return 0;
}