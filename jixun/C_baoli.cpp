#include <bits/stdc++.h>
using namespace std;
inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}

int dfs(int x,int y){
    int res=0;
    if (x==1) return y; 
    if (y==1) return x;
    if (gcd(x,y)==1) res++;
    return max(dfs(x-1,y),dfs(x,y-1))+res;
}
int main(){
    int x,y;
    while (cin>>x>>y)
    cout(dfs(x,y));
}