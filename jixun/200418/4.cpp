#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    for (int i=0;i<s.length();i++){
        char ch;
        if (s[i]+3>'z') ch=s[i]+3-26;
        else ch=s[i]+3;
        cout<<ch;
    }
}