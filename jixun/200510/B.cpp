#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
stack <char> s1;
stack <char> s2;

int main(){
    string s;
    while (getline(cin,s)){
        while (!s.empty()) s1.pop();
        while (!s2.empty()) s2.pop();
        getchar();
        int len=s.length();
        int i=0;
        int kh=0;
        while (s[i]!='\0'){
            while (s[i]==' ') i++;

            if (s[i]=='!' || s[i]=='|' || s[i]=='&') s1.push(s[i]);
            if (s[i]=='V' || s[i]=='F') s2.push(s[i]);
            if (s[i]=='('){
                kh++;
                s2.push(s[i]);
            }

            if (s[i]==')'){
                s2.pop();
            }

            while (s1.top()!='(' || !s1.empty()){
                char ss=s1.top();
                char tt=s2.top();
                s1.pop(); s2.pop();
                if (ss=='!') {if (tt=='V') s2.push('F'); else s2.push('V');}
                else {
                    char kk=s2.top();
                    s2.pop();
                    if (ss=='|') {if (tt=='V' || kk=='V') s2.push('V'); else s2.push('F');}
                    if (ss=='&') {if (tt=='V' && kk=='V') s2.push('V'); else s2.push('F');}
                }
            }

        }
        cout<<s2.top()<<endl;
    }
}