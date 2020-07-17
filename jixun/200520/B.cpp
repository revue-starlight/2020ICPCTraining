#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,d,e;
int main(){
    cin>>n>>d>>e;
    e=e*5;
    if (d<e) swap(d,e);
    int maxx=n/d;
    int ans=INT_MAX;
    for (int i=0;i<=maxx;i++){
        int tempans=(n-d*i)%e;
        if (tempans<ans) ans=tempans;
    }
    cout<<ans;
}