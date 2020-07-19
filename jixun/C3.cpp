#include <bits/stdc++.h>
using namespace std;
inline int gcd(int a,int b) {
    return b>0 ? gcd(b,a%b):a;
}
int a[1001][1001];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i=1;i<=1000;i++) a[1][i]=a[i][1]=i;
    for (int i=2;i<=1000;i++)
        for (int j=2;j<=1000;j++){
            a[i][j]=max(a[i-1][j],a[i][j-1]);
            if (gcd(i,j)==1){
                a[i][j]++;
            }
        }
    int t;
    cin>>t;
    while (t--){
        int aa,bb;
        cin>>aa>>bb;
        cout<<a[aa][bb]<<endl;
    }
}