#include <bits/stdc++.h>
using namespace std;
priority_queue <int> q;
long long x,n,sum,ans;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&x);
        sum+=x;
        q.push(x);
    }
    while (!q.empty()){
        ans+=sum;
        x=q.top();
        sum-=x;
        q.pop();
    }
    ans-=x;
    printf("%ld\n",ans);
    return 0;
}