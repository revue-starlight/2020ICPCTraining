#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int p;
int main(){
    while (cin>>n){
        while (n--){
        int p=1;
        int cnt=0;
        cin>>s;
        int len=s.length();

        while (p<=len){
            cnt=1;
            while (s[p]==s[p-1]) {cnt++; p++;}
            if (cnt==1) {cout<<s[p-1];}
                else cout<<cnt<<s[p-1];
                p++;
        }
        cout<<endl;
        }
    }   
}