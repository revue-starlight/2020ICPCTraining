#include <iostream>
using namespace std;
int a[21],weight[2001],m,n,b[21],sum,ans,cnt;

void dp()
{
    for (int i=1;i<=sum;i++) weight[i]=0; weight[0]=1; cnt=0; //initialize
    for (int i=1;i<=n;i++)
    {
        if (a[i]==0)
        for (int j=sum;j>=b[i];j--)
            if (weight[j-b[i]]!=0) weight[j]=1;
    }
    for (int i=1;i<=sum;i++)
        if (weight[i]) cnt++;
    if (cnt>ans) ans=cnt;
    return;
}

void dfs(int depth,int initial)
{
    if (depth==m) {dp(); return;}
    else
    {
        for (int i=initial;i<=n;i++){
            a[i]=1;
            dfs(depth+1,i+1);
            a[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {cin>>b[i]; sum+=b[i];} //记录了sum，这样dp时循环就方便一点了。
    dfs(0,1);
    cout<<ans;
}