#include <bits/stdc++.h>
using namespace std;
int mp[8][8];
int s[8][8];
int ans=0;
int levelnow=0;
bool a[8];
inline void dye(int x,int y){
    for (int i=0;i<8;i++) s[i][y]++;
    for (int i=0;i<8;i++) s[x][i]++;
    for (int p=x-1,q=y-1;(p>=0&&q>=0);p--,q--) s[p][q]++;
    for (int p=x+1,q=y+1;(p<8&&q<8);p++,q++) s[p][q]++;
    for (int p=x-1,q=y+1;(p>=0&&q<8);p--,q++) s[p][q]++;
    for (int p=x+1,q=y-1;(p<8&&q>=0);p++,q--) s[p][q]++;
    s[x][y]--;
}

inline void undye(int x,int y){
    for (int i=0;i<8;i++) s[i][y]--;
    for (int i=0;i<8;i++) s[x][i]--;
    for (int p=x-1,q=y-1;(p>=0&&q>=0);p--,q--) s[p][q]--;
    for (int p=x+1,q=y+1;(p<8&&q<8);p++,q++) s[p][q]--;
    for (int p=x-1,q=y+1;(p>=0&&q<8);p--,q++) s[p][q]--;
    for (int p=x+1,q=y-1;(p<8&&q>=0);p++,q--) s[p][q]--;
    s[x][y]++;
}
inline void dfs(int level){
    if (level==8) 
        {ans++; return;}
    else
    if (a[level]) dfs(level+1);
    else
    for (int i=0;i<8;i++){
        if (!s[level][i]) {dye(level,i); dfs(level+1); undye(level,i);}
    }
}
int main(){
    while (cin>>mp[0][0]){
        memset(a,0,sizeof(a));
        ans=0;
        memset(s,0,sizeof(s));
        for (int i=1;i<8;i++) cin>>mp[0][i];
        for (int i=1;i<8;i++){
            for (int j=0;j<8;j++) cin>>mp[i][j];
        }
        int cnt=0;
        for (int i=0;i<8;i++)
         for (int j=0;j<8;j++){
            if (mp[i][j]==1){
                cnt++;
                a[i]=true;
                dye(i,j);
            }
        }
        dfs(0);
        cout<<ans<<endl;
    }
}