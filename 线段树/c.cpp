#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    vector <vector<int> > a (n,vector<int>(m));
    for(int i=0;i<n;i++){  // kkkk%n=0
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            a[i][j]--; //为了更好的膜法
        }
    }
    long long ans=0;
    for(int j=0;j<m;j++){
        vector <int> cnt(n);
        for(int i=0;i<n;i++){//操作column
            if(a[i][j]%m==j){ //是column里面的东西
                int pos=a[i][j]/m; //要移动几次
                if (pos<n) cnt[(n+i-pos)%n]++; //防止把n给加了
            }
        }
        int tmp=n-cnt[0];
        for(int i=1;i<n;i++){
            tmp=min(tmp,n-cnt[i]+i);
        }
        ans+=tmp;
    }
    cout<<ans<<endl;
}