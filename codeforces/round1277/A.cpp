#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        int cnt=0;
        cnt=9*s.length()-9;
        int t=s[0];
        int ans=0;
        for (int i=0;i<s.length();i++)
        {
            ans=ans*10+((int)t-48);
        }
        int ans2=0;
        for (int i=0;i<s.length();i++)
        {
            ans2=ans2*10+(int)s[i]-48;
        }
        cnt+=(int)s[0]-48;
        
        if (ans-ans2>0) cnt--;
        cout<<cnt<<endl;
    }
}