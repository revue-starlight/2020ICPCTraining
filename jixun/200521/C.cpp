// cf - 1214 D
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
vector <int> vec[maxn];
int n,m;
int vis[maxn];
inline int in_pic(int x,int y)
{
    if (x<0 || x>=n || y<0 ||y>=m) return 0;
    else return 1;}
bool dfs(int x,int y){
    if (!in_pic(x,y)) return false;
    if (vec[x][y]==1 && vis[x*m+1]==1) return false;
    for (int i=0;i<2;i++){
        
    }
}
int main(){
    //CF - 1214 D
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            char ch; cin>>ch;
            if (ch=='.') vec[i].push_back(0);
                else vec[i].push_back(1);
        }
    if (!dfs(0,0)) {cout<<0; return 0;}
    vis[0]=0;
    if (!dfs(0,0)) cout<<1; else cout<<2;
    return 0;
}