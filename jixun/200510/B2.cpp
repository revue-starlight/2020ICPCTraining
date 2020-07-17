#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

char cal(string s){
        stack <char> fuhao;
        stack <char> shuzi;
        while (!fuhao.empty()) fuhao.pop();
        while (!shuzi.empty()) shuzi.pop();    
        int t=-1;
        int len=s.length();
        while (t==-1 || s[t]!='\0'){
            t++;
            while (s[t]==' ' && t<len) t++;
            if (t==len) break;
        if (s[t]=='('){
            int l=t;
            int Ljs=0;
            t++;
            while (Ljs!=0 || s[t]!=')') {
                if (s[t]=='(') Ljs++; 
                else if (s[t]==')') Ljs--;
                t++;
            }
            int r=t;
            string ss=s.substr(l+1,r-l-1);
            shuzi.push(cal(ss));
        }
        
        if (s[t]=='V' || s[t]=='F')
            shuzi.push(s[t]);
        
        if (s[t]=='|' || s[t]=='&'){
            if (!fuhao.empty()){
                if (s[t]=='|'){
                    if (fuhao.top()=='!'){
                        fuhao.pop();
                        if (shuzi.top()=='V') {shuzi.pop(); shuzi.push('F');}
                        else {shuzi.pop(); shuzi.push('V');}
                    }
                    if (!fuhao.empty() && fuhao.top()=='|'){
                        char shuzi1=shuzi.top();
                        shuzi.pop();
                        char shuzi2=shuzi.top();
                        shuzi.pop();
                        char fuhao1=fuhao.top();
                        fuhao.pop();
                            if (shuzi1=='V' || shuzi2=='V') shuzi.push('V');
                                else shuzi.push('F');
                        }
                     if (!fuhao.empty() && fuhao.top()=='&'){
                        char shuzi1=shuzi.top();
                        shuzi.pop();
                        char shuzi2=shuzi.top();
                        shuzi.pop();
                        char fuhao1=fuhao.top();
                        fuhao.pop();
                            if (shuzi1=='V' && shuzi2=='V') shuzi.push('V');
                                else shuzi.push('F');
                        }
                    }
                    if (s[t]=='&'){
                    if (fuhao.top()=='!'){
                        fuhao.pop();
                        if (shuzi.top()=='V') {shuzi.pop(); shuzi.push('F');}
                        else {shuzi.pop(); shuzi.push('V');}
                    }
                     if (!fuhao.empty() && fuhao.top()=='&'){
                        char shuzi1=shuzi.top();
                        shuzi.pop();
                        char shuzi2=shuzi.top();
                        shuzi.pop();
                        char fuhao1=fuhao.top();
                        fuhao.pop();
                            if (shuzi1=='V' && shuzi2=='V') shuzi.push('V');
                                else shuzi.push('F');
                        }
                    }

                }
                fuhao.push(s[t]);
            }
            if (s[t]=='!') fuhao.push('!');
        }
            
            while (!fuhao.empty()){
                char fuhao1=fuhao.top();
                fuhao.pop();
                if (fuhao1=='!'){
                    char shuzi1=shuzi.top();
                    shuzi.pop();
                    if (shuzi1=='F') shuzi.push('V'); else shuzi.push('F');
                }
                else {
                    char shuzi1=shuzi.top();
                    shuzi.pop();
                    char shuzi2=shuzi.top();
                    shuzi.pop();
                    if (fuhao1=='&'){
                            if (shuzi1=='V' && shuzi2=='V') shuzi.push('V');
                                else shuzi.push('F');
                    }
                    if (fuhao1=='|'){
                            if (shuzi1=='V' || shuzi2=='V') shuzi.push('V');
                                else shuzi.push('F');
                    }
                }
            }
            return shuzi.top();
}
int main(){
    string s;
    int T=0;
     while (getline(cin,s)){
         T++;
            cout<<"Expression "<<T<<": "<<cal(s)<<endl;
    }
}