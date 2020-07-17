#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    getchar();
   // freopen("out.out","w",stdout);
    for (int kaze=1;kaze<=t;kaze++){
        string s;
        getline(cin,s);
        int len=s.length();
        int now=0;
        cout<<"Case #"<<kaze<<": ";
        for (int i=0;i<len;i++){
            int d=s[i]-'0';
            if (d>now) {for (int j=1;j<=d-now;j++) cout<<"(";  cout<<s[i];}
            if (d<now) {for (int j=1;j<=now-d;j++) cout<<")";  cout<<s[i];}
            if (d==now) cout<<s[i];
            now=d;
        }
         if (0<now) {for (int j=1;j<=now;j++) cout<<")";}
     if (kaze<t)   cout<<endl;
    }
    return 0;
}