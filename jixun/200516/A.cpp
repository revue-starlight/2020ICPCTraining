#include <iostream>
using namespace std;
int main(){
    int n,a,b;
    cin>>n;
    while (n--){
        int x;
        cin>>a>>b>>x;
        if (x%3==0) cout<<a<<endl; 
        if (x%3==1) cout<<b<<endl;
        int p=a^b;
        if (x%3==2) cout<<p<<endl;
    }
}