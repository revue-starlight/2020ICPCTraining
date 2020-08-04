#include <bits/stdc++.h>
using namespace std;
#define ll long long
int bo[1000];
int ans[1000];
int n;
void dfs(int x){
    if (x==n){
        for (int i=1;i<=n;i++){
            if (bo[i]==-1) ans[i]++;
        }
        return;
    }
    int tmp;
    for (int i=1;i<=n;i++) if (bo[i]==-1) {tmp=i; bo[i]=1; break;}
    for (int i=1;i<=n;i++){
        if (bo[i]==-1){
        bo[i]=1;
        dfs(x+2);
        bo[i]=-1;
        }
    }
    bo[tmp]=-1;
}
int main(){
    cin>>n;
    memset(bo,-1,sizeof(bo));
    dfs(1);
    int sum=0;
    for (int i=1;i<=n;i++){
        cout<<i<<" "<<ans[i]<<endl;
        sum+=ans[i];
    }
    cout<<sum<<endl;
}