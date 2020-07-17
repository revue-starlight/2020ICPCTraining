#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    while (n--){
        int x,y;
        cin>>x>>y;
        if (x%2==0 || y%2==0){
            cout<<x*y/2<<endl;
        }
        else{
                cout<<(x*y+1)/2<<endl;
        }
    }
}