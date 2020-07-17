#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    int t;
    cin>>t;
    while (t--){
        cin>>n>>x;
        int po[10001]; memset(po,0,sizeof(po));
        for (int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            po[a]++; po[b]++;
        }
        if (po[x]==1 || po[x]==0) { cout<<"Ayush"<<endl;}
        else {
            if (n&1) {cout<<"Ashish"<<endl;} else cout<<"Ayush"<<endl;
        }
    }
}