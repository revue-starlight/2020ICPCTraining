#include <iostream>
using namespace std;
int main(){
 //   freopen("data.in","r",stdin);
  //  freopen("data.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int sum=0;
    while (a!=b){
        while (a>b){
            if (a%2) a++,sum++;
            else a/=2,sum++;
        }
        while (a<b){
            sum++,a++;
        }
    }
    cout<<sum<<endl;
    return 0;
}