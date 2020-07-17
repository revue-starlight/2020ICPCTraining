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