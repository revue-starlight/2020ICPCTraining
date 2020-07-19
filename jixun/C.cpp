#include <bits/stdc++.h>
using namespace std;
const long N = 1001;     
long prime[N] = {0},num_prime = 0;      
int isNotPrime[N] = {1, 1};

inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;}
int main(){
    int T;
    cin>>T;
    for (int i=1;i<=10;i++){
    for (int j=1;j<=10;j++){
    int res=0;
    int xx=i,yy=j;
    if (xx<yy) swap(xx,yy);
    while (yy!=1){
        if (gcd(xx,yy)==1) res++;
        yy--;
    }
    res+=xx;
    cout<<res<<" ";
    }
    cout<<endl;
    }
}