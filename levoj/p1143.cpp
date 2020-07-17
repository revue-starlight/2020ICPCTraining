#include <bits/stdc++.h>
using namespace std;
string a[101];
void solve(){
    int n; cin>>n;
    int len=INT_MAX,len_id=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i].length()<len) {len=a[i].length(); len_id=i;}
    }
    for (int i=len;i>=1;i--){
        for (int j=0;j<len-i+1;j++){ //[j,j+i-1]
        string s=a[len_id].substr(j,i);
        int k=1;
        for (k=1;k<=n;k++){
            bool b1=1,b2=1;
            if (a[k].find(s)==a[k].npos) b1=0;
            reverse(s.begin(),s.end());
            if (a[k].find(s)==a[k].npos) b2=0;
            reverse(s.begin(),s.end());
            if ((!b1) && (!b2)) break;
        }
        if (k==n+1) {
            cout<<i<<endl;
            return;
        }
        }
    }
}
int main(){
    int t;
    while (cin>>t){
        while (t--) solve();
    }
}