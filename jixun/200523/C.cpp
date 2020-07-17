#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll A,B,C,D,x,y;
int main(){
    int ans=0;
    cin>>A>>B>>C>>D;
    for (int x=A;x<=B;x++){
        int ans1=(D-x-B);
        int ans2=(D-x-C);
        if (ans1<0) ans1=0; if (ans2<0) ans2=0;
        ans+=(ans1+ans2)*(ans2-ans1+1)/2;
    }
    cout<<ans<<endl;
}   