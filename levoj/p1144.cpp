#include <bits/stdc++.h>
using namespace std;
int m,p,q;
const int maxn=1e5+20;
bool notprime[maxn];
int tot=0;
int prime[maxn];
int main(){
    memset(notprime,0,sizeof(notprime));
    memset(prime,0,sizeof(prime));
    for (int i=2;i<maxn;i++){
        if (!notprime[i])
            prime[tot++]=i;
        for (int j=0;j<tot && prime[j]*i<maxn;j++){
            notprime[i*prime[j]]=1;
            if (!(i%prime[j]])) break;
        }
    }
    while (cin>>m>>p>>q){
       if (m==0) continue;

    }
}