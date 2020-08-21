#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e5+10;
int fa[maxn];
inline void find(ll x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
    int n,m;
    cin>>n>>m;
    
}