#include <iostream>
#include <cstdio>
using namespace std;
bool hole[1000006];
int n,m,k;
int main()
{
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++)
    {
        int x; cin>>x; hole[x]=1;
        if (x==1){cout<<1<<endl; return 0;}
    }
    int bones=1;
    for (int i=1;i<=k;i++)
    {
        int l,r;
        cin>>l>>r;
        if (bones==l || bones==r)
        {
            bones=(l+r)-bones;
        }
        if (hole[bones]) {cout<<bones<<endl; return 0;}
    }
    cout<<bones;
}