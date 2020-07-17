#include <bits/stdc++.h>
using namespace std;
bool isprime[100];
int n;
int ans[19];
bool used[17];

void print(){
    for (int i=1;i<n;i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
}
void dfs(int level){
    if (level>n) {
        if (isprime[ans[1]+ans[n]] && isprime[ans[n]+ans[n-1]]) print();
        return;
    }

    if (!isprime[ans[level-1]+ans[level-2]] && level>2) return;
    
        for (int i=1;i<=n;i++){
            if (!used[i]){
                used[i]=1;
                ans[level]=i;
                dfs(level+1);
                used[i]=0; ans[level]=0;
            }
        }
}
int main(){
    freopen("data.in","r",stdin);
    freopen("data1.out","w",stdout);
    memset(isprime,0,sizeof(isprime));
    isprime[2]=isprime[3]=isprime[5]=isprime[7]=isprime[11]=isprime[13]=isprime[17]=isprime[19]=1;
    isprime[23]=isprime[29]=isprime[31]=1;
    int tot=0;
    while(cin>>n){
        if (n==0) {tot=0; continue;}
        tot++;
        printf("Case %d:\n",tot);
        memset(ans,0,sizeof(ans));
        memset(used,0,sizeof(used));
        ans[1]=1;
        used[1]=1;
        if (n==1) cout<<1<<endl;
        else dfs(2);
        printf("\n");
    }
}