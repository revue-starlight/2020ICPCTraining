#include <bits/stdc++.h>
using namespace std;
#define maxn 100006
#define maxm 10001
int main(){
    long long n,m;
    cin>>n;
    long long a[maxn];
    long long b[maxn];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    long long c[3];
    long long l[3];
    long long r[3];
    memset(c,0,sizeof(c));
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    for (int i=1;i<=n;i++) {cin>>a[i];}
    for (int i=1;i<=n;i++) {cin>>b[i]; l[i%3]+=b[i];}
    for (int i=1;i<=n;i++) 
    {c[(i)%3]+=a[i]*l[0];
    c[(i+1)%3]+=a[i]*l[1];
    c[(i+2)%3]+=a[i]*l[2];}
    cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<endl;
}