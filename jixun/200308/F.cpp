#include <bits/stdc++.h>
using namespace std;
#define maxn 200000
struct node{
    int t,h;
    bool operator < (const node &x) const{
        return t<x.t;
    }
}a[maxn];
priority_queue <node> q;

bool cmp(const node &a,const node &b){
    if (a.h==b.h) return a.t<b.t; else return a.h<b.h;
}

int main(){
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&a[i].t,&a[i].h);
    sort(a+1,a+1+n,cmp);
    int now_time=0;
    for (int i=1;i<=n;i++) {
        now_time+=a[i].t;
        q.push(a[i]);
        while (now_time>a[i].h) {
            node k=q.top();
            q.pop();
            now_time-=k.t;
        }
    }
    cout<<q.size()<<endl;

}