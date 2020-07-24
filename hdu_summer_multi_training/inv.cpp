#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+9;
int main(){
    cout<<((ll)383008016*383008016) % mod<<endl;
    for (ll i=1;i<mod;i++){
        if (((i%mod)*(i%mod))%mod==5)
        {cout<<i<<endl;
        break;}
    }
}