#include <bits/stdc++.h>
using namespace std;
void swapp(int *a,int *b){
    int t=*a;
    cout<<"a="<<a<<" *a="<<*a<<endl;
    cout<<"b="<<b<<" *b="<<*b<<endl;
    *a=*b;
    *b=t;
    cout<<"a="<<a<<" *a="<<*a<<endl;
    cout<<"b="<<b<<" *b="<<*b<<endl;
}
int main(){
    int a,b;
    a=5; b=3;
    cout<<"&a="<<&a<<" &b="<<&b<<endl;
    swapp(&a,&b);
    cout<<a<<" "<<b<<endl;
} v