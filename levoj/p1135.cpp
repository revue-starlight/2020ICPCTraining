#include <bits/stdc++.h>
using namespace std;
struct aaaa{
    int year;
    string s;
    bool operator < (const aaaa x)const{
        return year<x.year;
    }
}a[1000];

int main(){
    int n;
    while (cin>>n){
        string s;
        int num;
        getchar();
        for (int i=1;i<=n;i++){
            getline(cin,s);
            int len=s.length();
            a[i].year=(s[len-1]-48)+s[len-2]*10-480+s[len-3]*100-4800+s[len-4]*1000-48000;
            a[i].s=s.substr(0,len-5);
        }
        sort(a+1,a+1+n);
    cout<<a[1].year<<" "<<a[1].s<<endl;
        for (int i=2;i<=n;i++) if (a[i].year!=a[i-1].year)cout<<a[i].year<<" "<<a[i].s<<endl;
    }
}