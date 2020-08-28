#include <bits/stdc++.h>
using namespace std;
double erfen(double x){
    
}
int main(){ 
    double l=0,r=100;
    while (r-l>=1e-7){
        double mid=(l+r)/2;
        if (erfen(mid)>0) r=mid;
        else l=mid;
    }
    cout<<(l+r)/2<<endl;
}