#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int T;
    cin>>T;
    while (T--){
        int x1,y1,x2,y2,x3,y3;
        cin>> x1>>y1>>x2>>y2>>x3>>y3;
        if ( ((x2-x1)*(y3-y2)-(y2-y1)*(x3-x2))<0) cout<<"Clockwise"<<endl;
        else cout<<"Counterclockwise"<<endl;
    }
    return 0;
}