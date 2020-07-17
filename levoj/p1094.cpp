#include <bits/stdc++.h>
using namespace std;
bool bo=true;

const int fx[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
const char fx2[4]={'N','S','E','W'};

int maze[11][11],n;
vector <int> vec;

bool check(int x,int y){
    if (x>n || x<1 || y>n || y<1 || maze[x][y]!=0) return 0;
    return 1;
}

void dfs(int x,int y,int cnt){
    if (cnt==n*n) {bo=0; return;}
    for (int i=0;i<4;i++){

        int xx=x+fx[i][0],yy=y+fx[i][1];
        int k=0;
        while (check(xx,yy)){
            k++;
            maze[xx][yy]=2;
            xx=xx+fx[i][0],yy=yy+fx[i][1];
        }
        xx=xx-fx[i][0],yy=yy-fx[i][1];

        if (k==0) continue; //本来就没路走，别死循环了

        vec.push_back(i);
        dfs(xx,yy,cnt+k); //向下搜索.
        if (!bo) {return;}// 搜到最后回家
        //没搜到最后,复原
        vec.pop_back();
        for (int j=1;j<=k;j++){
            maze[xx][yy]=0;
            xx=xx-fx[i][0],yy=yy-fx[i][1];
        }

    }
}



int main(){
    int t,cnt=0;
    while (cin>>n){
        cnt=0;
        bo=1; memset(maze,0,sizeof(maze));
         while (vec.size()) 
          vec.pop_back();
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++){
            cin>>maze[i][j];
            if (maze[i][j]) cnt++;
            }


        for (int i=1;i<=n;i++){
            if (!bo) break;
            for (int j=1;j<=n;j++){
                if (!maze[i][j]){
                maze[i][j]=2;
                dfs(i,j,cnt+1);
                maze[i][j]=0;
                if (bo==0){
                    cout<<i<<" "<<j<<endl;
                    for (int i=0;i<vec.size();i++){
                        cout<<fx2[vec[i]];
                    }
                    cout<<endl;
                    break;
                }
                
                while (vec.size()) vec.pop_back();
                }
            }
        }


    }
}