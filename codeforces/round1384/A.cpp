#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll a[101];
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        s="";
        for (int i=0;i<n;i++){
            cin>>a[i];
        }
        for (int i=0;i<200;i++){
            s=s+char(i%26+'a');
        }
        cout<<s<<endl;
        for (int i=0;i<n;i++){
            for (int j=a[i];j<199;j++) s[j]=(char)((s[j]-'a'+1)%26+'a');
            cout<<s<<endl;
        }
    }
}