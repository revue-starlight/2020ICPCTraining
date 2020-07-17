#include <bits/stdc++.h>
using namespace std;
#define maxn 1000006

int n,m;
vector <int> vec[maxn];
bool bo=false;
void dfs(int x,int y){
    vec[x][y]=2;
    if (x==n && y==m) bo=true;
    if (bo==true) return;
    int tarx=x+1,tary=y;
    if (in_pic(tarx,tary) && vec[tarx][tary]==1) dfs(tarx,tary);
    tarx=x; tary=y+1;
    if (in_pic(tarx,tary) && vec[tarx][tary]==1) dfs(tarx,tary);
    
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
    dfs(0,0,1);
    
}