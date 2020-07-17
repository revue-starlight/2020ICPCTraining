#include <iostream>
using namespace std;
int a[1000];
int main()
{
    int n,m,tot;
    cin>>n>>m>>tot;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]==0) a[i]=0x3f3f3f3f;
    }
    int i=1;
    while (1)
    {
        if (m+i<=n && a[m+i]<=tot)
        {
            cout<<i*10<<endl;
            return 0;
        }
        if (m-i>0 && a[m-i]<=tot)
        {
            cout<<i*10<<endl;
            return 0;
        }
        i++;
    }
}