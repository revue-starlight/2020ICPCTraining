#include <bits/stdc++.h>
#define maxn 100
#define ll long long
using namespace std;
struct node{
    int u,v,next;
}edge[maxn];
ll cnt=1,head[maxn];
void build(ll u,ll v,ll next){
    edge[cnt].u=u; edge[cnt].v=v; edge[cnt].next=head[u]; head[u]=cnt; cnt++;
}

int main(){

}