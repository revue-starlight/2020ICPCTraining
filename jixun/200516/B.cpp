#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main(){
    int cnt=0;
    int n;
    cin>>n;
    for (int i=1;i<=n;i=i+4)
        for (int j=1;j<=n;j=j+4)
        for (int x=0;x<4;x++)
         for (int y=0;y<4;y++)
         a[i+x][j+y]=cnt++;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
       { cout<<a[i][j]<<" ";
        if (j==n) cout<<endl;}

}