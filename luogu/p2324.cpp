/*yokkkkkkiii v9:52=*/
#include <bits/stdc++.h>
using namespace std;
int a[5][5];
int cnt;
const int goal[5][5]={
    {1,1,1,1,1},
    {0,1,1,1,1},
    {0,0,2,1,1},
    {0,0,0,0,1},
    {0,0,0,0,0}
};

const int fx[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

int evaluate()
{
    int cnt=0;
    for (int i=0;i<5;i++)
        for (int j=0;j<5;j++)
        {
            if (a[i][j]!=goal[i][j])
                cnt++;
        }
    return cnt;
}
bool bo=false;
int ans=0x3f3f3f;
void search(int x,int y,int depth,int maxdepth){
   int k=evaluate();
/*   if (k==2)
     {cout<<"here it is!!"<<endl;} */
   if (k==0) {ans=min(ans,depth); cnt++; cout<<"ans= "<<ans<<" cnt="<<cnt<<endl; return;} 
   if (k+depth-1>maxdepth || bo) return;
    for (int i=0;i<8;i++){
        if (x+fx[i][0]<5 && x+fx[i][0]>=0 && y+fx[i][1]<5 && y+fx[i][1]>=0)
        {
        swap(a[x][y],a[x+fx[i][0]][y+fx[i][1]]);
        search(x+fx[i][0],y+fx[i][1],depth+1,maxdepth);
        if (bo) return;
        swap(a[x][y],a[x+fx[i][0]][y+fx[i][1]]);
        }
    }
}


int main()
{
    int t;
    cin>>t;
    for (int pp=1;pp<=t;pp++)
    {
        int dx,dy;
        for (int i=0;i<5;i++)
        {
            getchar();
            for (int j=0;j<5;j++)
            {
                char xxx;
                cin>>xxx;
                if (xxx=='1') a[i][j]=1;
                else if (xxx=='0') a[i][j]=0; 
                else {a[i][j]=2; dx=i; dy=j;}
            }
        }

search(dx,dy,0,15);
      /*  for (int i=1;i<=15;i++){
            bo=false;
            search(dx,dy,0,i);
            if (bo) break;
            if (i==15) cout<<"-1"<<endl;
        }*/
    }
}