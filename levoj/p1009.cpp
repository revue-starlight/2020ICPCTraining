#include <bits/stdc++.h>
using namespace std;
bool notprime[10001];
int prime[1001];
int main(){
    notprime[1]=1; int size=0;
    for (int i=2;i<=5000;i++){
        if (!notprime[i])
            prime[size++]=i;
            for (int j=0;j<size && i*prime[j]<5000;j++){
                notprime[prime[j]*i]=1;
                if (!(i%prime[j])) break;
            }
    }
    int n;
    while (cin>>n){
        int t=0,ans=0;
        while (prime[t]<n) {ans+=prime[t]; t++;}
        cout<<ans<<endl;
    }
}