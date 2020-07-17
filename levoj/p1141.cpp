#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2,s3;
    while (cin>>s1){
        getchar();
        if (s1=="ENDOFINPUT") continue;
        getline(cin,s2);
        getchar();
        getline(cin,s3);
        int len=s2.length();
        for (int i=0;i<len;i++){
            if (s2[i]=='A') cout<<"V";
            else if (s2[i]=='B') cout<<"W";
            else if (s2[i]=='C') cout<<"X";
            else if (s2[i]=='D') cout<<"Y";
            else if (s2[i]=='E') cout<<"Z";
            else if (s2[i]>'A' && s2[i]<='Z') cout<<char(s2[i]-5);
            else cout<<s2[i];
        }
            cout<<endl;
    }
}