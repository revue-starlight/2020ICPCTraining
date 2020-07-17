#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin>>n)
    {
        string s;
        string a[1001];
        for (int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        for (int i=1;i<=n;i++)
        {if (a[i]!="China") cout<<a[i]<<endl;}
        cout<<"China"<<endl;
    }
}