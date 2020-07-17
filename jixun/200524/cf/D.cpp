#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
int prime[maxn];
bool notprime[maxn]={1,1};

int main(){
    int primecnt=0;
    for (int i=2;i<maxn;i++){
        if (!notprime[i])
            prime[primecnt++]=i;
        for (int j=0;j<primecnt;j++){
            notprime[i*prime[j]]=1;
            if (!(i%prime[j])) break;
        }
    }
    for (int i=0;i<primecnt;i++) cout<<prime[i]<<endl;

}