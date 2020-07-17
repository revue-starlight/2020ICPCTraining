#include <bits/stdc++.h>
using namespace std;
priority_queue <int> q;
int main()
{
    int n=0; cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x; cin>>x;
        x=-x;
        q.push(x);
    }
    int ans=0;
    while (1)
    {
        int a=q.top(); q.pop();
        if (q.empty()) {cout<<ans*-1; return 0;}
        int b=q.top(); q.pop();
        ans=ans+a+b;
        q.push(a+b);
    }
}