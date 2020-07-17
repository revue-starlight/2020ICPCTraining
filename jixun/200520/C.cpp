#include <bits/stdc++.h>
using namespace std;
#define maxn 1000000
vector <int> vec[maxn];
bool bo;
int n,m;
int maxx,minx,maxy,miny;
const int superfx[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int in_pic(int x,int y){
    if (x<0 || x>=n || y<0 || y>=m) return 0; else return 1;
}
int used;

void dfs(int x,int y){
    vec[x][y]=3;
    if (miny>y) miny=y;
    if (maxy<y) maxy=y;
    if (minx>x) minx=x;
    if (maxx<x) maxx=x;
    if (minx==0 && maxx==n || minx==0 && miny==0 || maxx==n && maxy==m || miny==0 && maxy==m) return;
    for (int i=0;i<8;i++){
        int tempx=x+superfx[i][0],tempy=y+superfx[i][1];
        if (in_pic(tempx,tempy) && vec[tempx][tempy]==1) vec[tempx][tempy]=2;
    }
    for (int i=0;i<8;i++) {
        int tarx=x+superfx[i][0],tary=y+superfx[i][1];
        if (in_pic(tarx,tary) && vec[tarx][tary]==0) dfs(tarx,tary);
    }
}

void dfs2(int x,int y){
    vec[x][y]=0;
    if (miny>y) miny=y;
    if (maxy<y) maxy=y;
    if (minx>x) minx=x;
    if (maxx<x) maxx=x;
    if ((minx==0 && maxx==n || minx==0 && miny==0 || maxx==n && maxy==m || miny==0 && maxy==m) && used==1) {bo=true;return;}

    for (int i=0;i<8;i++) {
        int tarx=x+superfx[i][0],tary=y+superfx[i][1];
        if (!used && in_pic(tarx,tary) && vec[tarx][tary]==2) {used++; dfs2(tarx,tary);}
        if (in_pic(tarx,tary) && vec[tarx][tary]==3) dfs2(tarx,tary);
    }
    if (vec[x][y]==2) used--;
}
int main(){
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            char ch;
            cin>>ch;
            if (ch=='.') vec[i].push_back(1);
            else vec[i].push_back(0);
        }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (vec[i][j]==0) {
                    maxx=0; minx=INT_MAX; maxy=0; miny=INT_MAX;
                    dfs(i,j);
                    if (minx==0 && maxx==n || minx==0 && miny==0 || maxx==n && maxy==m || miny==0 && maxy==m)
                    {cout<<0<<endl; return 0;} 
            }
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (vec[i][j]==3) {
                    used=0;
                    bo=false;
                    maxx=0; minx=INT_MAX; maxy=0; miny=INT_MAX;
                    dfs2(i,j);
                    if (bo)
                    if (minx==0 && maxx==n || minx==0 && miny==0 || maxx==n && maxy==m || miny==0 && maxy==m)
                    {cout<<1<<endl; return 0;} 
            }
        }
    }
    
    cout<<2<<endl; return 0;
    
    
}