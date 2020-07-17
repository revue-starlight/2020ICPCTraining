#include <bits/stdc++.h>
#include <string>
using namespace std;

bool work(string s,string t){
    int it=0,i,x=s.length();
    for (i=0;i<x;i++){
    it = t.find(s[i],it);
    if (it ==string::npos) return false;
    it++;
    }
    return true;
}

int main(){
    string s,t;
    while (cin>>s>>t)
    {
    if (work(s,t))   cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    }
}