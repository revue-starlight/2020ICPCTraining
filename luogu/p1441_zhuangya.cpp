#include <bitset>
#include <iostream>
using namespace std;
int w[21],n,m,cnt,ans;
int count(int x)
{
    int t=0;
    while (x)
    {
        if (x&1) t++;
        x/=2;
    }
    return t;
}

int main()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)
    cin>>w[i]; //w[i]用来存每个砝码的质量
    int li=1<<n;
    for (int i=1;i<li;i++)
        {
            if (count(i)==n-m)  
            {
                bitset <2001> b;
                b[0]=1;
                for (int j=0;j<n;j++)
                    if (i & (1<<j))
                    b |=b<<w[j];
                cnt=b.count();
                if (ans<cnt) ans=cnt;
            }
        }
    cout<<ans-1<<endl;
}