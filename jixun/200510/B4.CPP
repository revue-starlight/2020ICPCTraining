#include <iostream>  
#include <string.h>  
using namespace std;  
string a="";  
bool result;  
int len=0;  
int j=0;  
bool term();  
bool expression();  
bool sub();  
  
bool term(){  
    bool result1;  
    if(a[j]=='!'){  
        j++;  
        result1 = !sub();  
    }else{  
        result1 = sub();  
    }  
  
    return result1;  
}  
  
bool expression(){  
    bool result1 = term();  
    while(j<len-1){  
        if(a[j]=='&'){  
            j++;  
            bool value = term();  
            result1 = result1 &&value;  
        }  
  
        if(a[j]=='|'){  
            j++;  
            bool value = term();  
            result1 = result1 ||value;  
        }  
  
        if(a[j]==')'){  
            //cout<<"b"<<endl;  
            j++;  
            break;  
        }  
  
  
    }  
    return result1;  
}  
  
bool sub(){  
    bool result2;  
    if(a[j]=='('){  
        j++;  
        result2 = expression();  
    }  
  
    if(a[j]=='V'){  
        j++;  
        result2 = true;  
    }  
  
    if(a[j]=='F'){  
        j++;  
        result2 = false;  
    }  
  
    if(a[j]=='!'){  
        result2 = term();  
    }  
    return result2;  
}  
  
int main()  
{  
    char b[100000];  
    int m=1;  
    while(cin.getline(b,100000)){  
        for(int i=0;i<strlen(b);i++){  
            if(b[i]!=' '){  
            a+=b[i];  
            }  
        }  
        len=a.length();  
        cout<<"Expression "<<m++<<":"<<(expression()?" V":" F")<<endl;  
        j=0;  
        a="";  
        memset(b,0,100000);  
    }  
    return 0;  
}  