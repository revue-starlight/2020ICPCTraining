#include <bits/stdc++.h>
using namespace std;
map <int,int> tmp_tong;
map<int,int>::iterator it;
void solve(){
    int n;
    cin>>n;
    int bo[1025];
    int a[1025];
    int tong[1025];
    memset(tong,0,sizeof(tong));
    for (int i=1;i<=n;i++){
        cin>>a[i];
        tong[a[i]]++;
    }
    bool suc=false;
    for (int i=1;i<=1024;i++){
        tmp_tong.clear();
        for (int j=1;j<=n;j++){
            tmp_tong[a[j]^i]++;
        }
        bool bo=true;
       for(it = tmp_tong.begin(); it != tmp_tong.end(); it++){
            if (tong[it->first]!=it->second) {bo=false; break;}
        }
        if (bo) {cout<<i<<endl; suc=true; break;}
    }
    if (!suc) {cout<<"-1"<<endl;}
    
}
int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
    }
}