#include <bits/stdc++.h>
using namespace std;
int w[100005][100005];
int dis[100005];
bool b[100005];
int main()
{
    int n=0,m=0,s=0;
    cin>>n>>m>>s;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++) w[i][j]=1000000009;
    for (int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        w[a][b]=c;
    }
    for (int i=1;i<=n;i++) dis[i]=1000000009;
    dis[s]=0; b[s]=1;
    int x=s;
    for (int i=2;i<=n;i++)
    {
        int minn=1000000009;
        int k;
        for (int y=1;y<=n;y++)
        {if (!b[y] && dis[x]+w[x][y]<dis[y]) {
            dis[y]=dis[x]+w[x][y];
             if (dis[y]<minn) 
             {k=y; minn=dis[y];}}
        }
        x=k;
        b[k]=1;
    for (int II=1;II<=n;II++) cout<<dis[II]<<" ";
    cout<<endl;
    }
}