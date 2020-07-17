#include <bits/stdc++.h>
using namespace std;

void swaps(int &a,int &b){
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
}
int main(){
    int a,b;
    cin>>a>>b;
    swaps(a,b);
    cout<<a<<" "<<b<<endl;
}