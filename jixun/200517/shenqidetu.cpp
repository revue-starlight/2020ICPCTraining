#include <iostream>
using namespace std;
int main(){
    char c;
    char x;
    x='0';
    while (cin>>c){
        if (c=='1' || c=='4' || c=='7'){
            switch (x){
                case '0': x='1'; break;
                case '1': x='2'; break;
                case '2': x='0'; break;
            }
        }
        if (c=='2' || c=='5' || c=='8'){
            switch (x){
                case '0': x='2'; break;
                case '1': x='0'; break;
                case '2': x='1'; break;
            }
        }
    }
    if (x=='0') cout<<"TRUE"; else cout<<"FALSE";
}