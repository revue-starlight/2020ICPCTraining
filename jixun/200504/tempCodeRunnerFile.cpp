#include <iostream>
#include <cmath>
#define PI acos(-1.0) 
using namespace std;
int a;
int main(){
int I=1.210;
double cosa = cos(a/360*2*PI)*cos(a/360*2*PI);

for (double a=0;a<=360;a=a+10){
    cosa=cos(a/360*2*PI)*cos(a/360*2*PI);
  
    double i;
    double i0=1.210;
    cin>>i;
    double ans=i/cosa;
    cout<<"i/i0="<<i/i0<<" cos^2(a)="<<cosa<<" "<<(i/i0)/cosa<<endl;
}
}