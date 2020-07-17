#include <bits/stdc++.h>
using namespace std;
int ans[100000];
int main(){
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        ans[x]++;
    }
    int t=n;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        if (ans[x]>0) ans[x]--,t--;
    }
    cout<<t<<endl;

}