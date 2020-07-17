#include <bits/stdc++.h>
using namespace std;
void swapp(int *a,int *b){
    int *t=a;
    a=b;
    b=t;
}
int main(){
    int a,b;
    a=5; b=3;
    swapp(&a,&b);
    cout<<a<<" "<<b<<endl;
}