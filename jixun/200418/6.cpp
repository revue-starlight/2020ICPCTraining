#include <bits/stdc++.h>
using namespace std;
int a[1004][1004];
int n,m,r,s;
inline void print(){
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=m+1;j++) printf("%4d",a[i][j]);
        printf("\n");
    }
}
void work(int heading,int pos,int x,int y){
    if (pos>n*m) return;
    a[x][y]=pos;
    if (pos==n*m) return;
    if (heading==1){
        while (a[x][y+1]==0) {a[x][y+1]=pos+1; pos++; y++; } 
        work(2,pos+1,x+1,y); 
    }
    else if (heading==2){
        while (a[x+1][y]==0) {a[x+1][y]=pos+1; pos++; x++; } 
        work(3,pos+1,x,y-1);
    }
    else if (heading==3){
        while (a[x][y-1]==0) {a[x][y-1]=pos+1; pos++; y--; } 
        work(4,pos+1,x-1,y); 
    }
    else {
        while (a[x-1][y]==0) {a[x-1][y]=pos+1; pos++; x--; } 
        work(1,pos+1,x,y+1);
    }
}
int main(){
    cin>>n>>m>>r>>s;
    for (int i=0;i<=m+1;i++) {a[0][i]=-1; a[n+1][i]=-1;}
    for (int i=0;i<=n+1;i++) {a[i][0]=-1; a[i][m+1]=-1;}
    
    work(1,1,1,1);
  //  print();
    cout<<a[r][s];
}