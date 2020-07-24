#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll a,b,c,d;
};
vector <node> vec[51];
int main(){
    int T;
    cin>>T;
    while (T--){
        int n,k;
        cin>>n>>k;
        for (int i=1;i<=n;i++){
            int typ;
            node tmp;
            cin>>typ>>tmp.a>>tmp.b>>tmp.c>>tmp.d;
            vec[typ].push_back(tmp);
        }
        for (int i=1;i<=k;i++){
            for (in)
        }
    }
}