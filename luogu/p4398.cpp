//jsoi2008 搜索题
#include <bits/stdc++.h>
using namespace std;
int m[51][51],l[51][51];
bool bo[51][51];
int i,j,n;
int maxx=-1;
inline int work(int a,int b,int x,int y)
{
    int p=1;
    while (1)
    {
        while (a+p<=n && b+p<=n && x+p<=n && y+p<=n)
        {
            for (int i=0;i<=p;i++)
            {
                if (m[a+p][i+b]!=l[x+p][i+y]) return p;
            }
            for (int i=0;i<=p;i++)
                if (m[i+a][b+p]!=l[i+x][y+p]) return p;
        p++;
        }
        return p;
    }
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) cin>>m[i][j];    
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) cin>>l[i][j];
   
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            for (int i1=1;i1<=n;i1++)
                for (int j1=1;j1<=n;j1++)
                {
                    if (i1!=i && j1!=j && m[i][j]==l[i1][j1] && m[i][j])
                    {
                        maxx=max(maxx,work(i,j,i1,j1));
                    }
                }
        }
        return 0;
}