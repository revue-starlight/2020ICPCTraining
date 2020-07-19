#include <bits/stdc++.h>
using namespace std;
const int maxn=3840;
const int maxm=2160;
int pic[maxn][maxm];
int stdd[maxn][maxm];
bool bo[maxn][maxm];
   void insert(int x1,int y1,int x2,int y2){
    stdd[x1][y1]+=pic[x1][y1];
    stdd[x1][y2+1]-=pic[x1][y1];
    stdd[x2+1][y1]-=pic[x1][y1];
    stdd[x2+1][y2+1]+=pic[x1][y1];
}
int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int tot=0;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            cin>>pic[i][j];
            insert(i,j,a-n+i,b-m+j);
            if (pic[i][j]) tot++;
        }
    for (int i=1;i<=a;i++)
        for (int j=1;j<=b;j++)
            stdd[i][j]+=stdd[i-1][j]+stdd[i][j-1]-stdd[i-1][j-1];
    for (int i=1;i<=a;i++){
        for (int j=1;j<=b;j++){
           cout<<(int)(((double)stdd[i][j])/tot*100)<<" ";
        }
        cout<<(int)(((double)stdd[i][b])/tot*100)<<endl;
    }
}