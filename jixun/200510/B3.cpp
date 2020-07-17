#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string s;
int T;
int t=0;
bool term();  
bool cal();  
bool sub();  

bool term(){  
    bool bo;  
    if(s[t]=='!'){ 
        t++;  
        bo = !sub();  
    }else{  
        bo = sub();  
    }  
  
    return bo;  
}  


bool cal(){  
    bool bo = term();  
    while(t<s.length()-1){  
        if(s[t]=='&'){  
            t++;  
            bool value = term();  
            bo = bo &&value;  
        }  
  
        if(s[t]=='|'){  
            t++;  
            bool value = term();  
            bo = bo ||value;  
        }  
  
        if(s[t]==')'){  
            t++;  
            break;  
        }  
  
  
    }  
    return bo;  
}  
  
bool sub(){  
    bool bo2;  
    if(s[t]=='('){  
        t++;  
        bo2 = cal();  
    }  
  
    if(s[t]=='V'){  
        t++;  
        bo2 = true;  
    }  
  
    if(s[t]=='F'){  
        t++;  
        bo2 = false;  
    }  
  
    if(s[t]=='!'){  
        bo2 = term();  
    }  
    return bo2;  
}  

int main(){
    while (getline(cin,s)){
        T++;
        t=0;
        cout<<"Expression "<<T<<": ";
        string a;
        int l;
        for (int i=0;i<s.length();i++) if (s[i]!=' ') a+=s[i];
        s=a;
        if (cal()) cout<<"V"<<endl; else cout<<"F"<<endl;
    }   
}