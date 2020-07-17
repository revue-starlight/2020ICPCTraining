#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int main(){
    int n;
    cin>>n;
    int t=1;
    int x=1;//x=1 向下 x=0向上
    int i=1,j=1;
    while (t<=n*n){
        a[i][j]=t;
        if (n%2==0 && i==1 && j==n) break;
        if (n%2!=0 && i==n && j==1) break;
        t++;
        if (x==1){
            i++; j--;
        }
        if (x==0){
            i--; j++;
        }
        if (i==0) {i++; x=1-x;}
        if (j==0) {j++; x=1-x;}
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (a[i][j]==0){
                a[i][j]=(1+n*n)-a[n+1-i][n+1-j];
            }
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<n;j++) cout<<a[i][j]<<" ";
        cout<<a[i][n]<<endl;
    }
}