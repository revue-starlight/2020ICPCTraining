#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while (n--){
        string s;
        cin>>s;
        int len=s.length();
        int a=0,b=0;
        bool sad=false;
        bool dead=false;
        for (int i=0;i<len;i++){
            if (s[i]=='a') a++;
            else if (s[i]=='b') {
                b++;
                if (a==b) sad=false;
                if (a>b) sad=true;
                if (a<b) dead=true;
            }
        }
        if (dead==true) cout<<"Dead Fang"<<endl;
        else {
            if (sad==false) cout<<"Happy Fang"<<endl;
            else cout<<"Sad Fang"<<endl;
        }
    }
}