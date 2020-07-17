#include <bits/stdc++.h>
using namespace std;
string s;
int minn;
int work(int l,int r)
{
    if (l==r) return 1;
    if ((r-l+1)%2!=0) return r-l+1;
    int mid=(l+r)/2;
    for (int i=l;i<=mid;i++)
        if (s[i]!=s[r-i]) return (r-l+1);
    return min(max(work(l,mid),work(mid+1,r)),(r-l+1)/2);
}

int main()
{
    cin>>s;
    cout<<work(0,s.length()-1)<<endl;

}