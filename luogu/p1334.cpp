#include <bits/stdc++.h>
using namespace std;
priority_queue <long long> q;
long long x,n,sum,ans;
int main()
{
    scanf("%ld",&n);
    for (int i=1;i<=n;i++){
        scanf("%ld",&x);
        q.push(-x);
    }
    while (!q.empty()){
        long long a=q.top();
        q.pop();
        if (q.empty()) break;
        long long b=q.top();
        q.pop();
        q.push(a+b);
        ans+=(a+b);
    }
    printf("%ld\n",-ans);
    return 0;
}