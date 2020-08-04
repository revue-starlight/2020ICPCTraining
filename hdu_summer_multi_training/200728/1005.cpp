#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
map <int,int> mp;
int ans=0;
int n,p,m;
int sum=0;
int main(){
    int T;
    cin>>T;
    while (T--){
        ans=0;
        cin>>n>>p;
        for (int i=1;i<=n;i++){
            int x;
            cin>>x;
            sum+=x;
            if (mp[p-x]){
                ans++;
                sum=0;
                mp.clear();
            }
            else {
            sum%=p;
            mp[sum]=1;
            }
        }
        cout<<ans<<endl;
    }

}