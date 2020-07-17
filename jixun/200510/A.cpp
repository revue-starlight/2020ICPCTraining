#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(){
    string s;
        bool bo=false,bo2=false;
    while (getline(cin,s)){
        int len=s.length();
        for (int i=0;i<s.length();i++){
            if (s[i]=='"' && !bo)
            {
                bo=true;
                s[i]=1;
            }
            if (s[i]=='"' && bo)
            {
                bo=false;
                s[i]=2;
            }
            /*if (s[i]=='\'' && s[i+1]!='\'' && !bo2)
            {
                bo=true;
                s[i]='`';
            }
            if (s[i]=='\'' && s[i+1]!='\'' && bo2)
            {
                bo=false;
            }*/
        }
        for (int i=0;i<s.length();i++){
            if (s[i]==1) cout<<"``";
            else if (s[i]==2) cout<<"''";
            else cout<<s[i];
        }
        cout<<endl;
    }
}