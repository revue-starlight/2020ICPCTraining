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
    for (int i=1;i<=20;i++)
    {
        for (int j=1;j<=20;j++)
        cout<<fixed<<setw(3)<<dfs(i,j);
        cout<<endl;
    }
}