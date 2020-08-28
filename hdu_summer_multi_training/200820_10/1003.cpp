#include <bits/stdc++.h>
using namespace std;
inline void solve(){
    int a[30][30];
    int n;
    cin>>n;
    if (n==0) {cout<<"1 1\n.\n"; return;}
    if (n==1) {cout<<"1 2\n.X\n"; return;}
    if (n==2) {cout<<"1 3\n.X.\n"; return;}
    if (n==3) {cout<<"2 2\nX.\n..\n"; return;}
    if (n==4) {cout<<"2 2\nXX\n..\n"; return;}
    if (n==5) {cout<<"3 2\n..\nX.\n..\n"; return;}
    if (n==6) {cout<<"3 2\nX.\n..\nX.\n"; return;}
    if (n==7) {cout<<"2 3\nXXX\n...\n"; return;}
    if (n==9) {cout<<"2 4\nXXX.\n....\n"; return;}
    if (n==10){cout<<"2 5\n.X.X.\n.....\n"; return;}
    if (n==12){cout<<"2 5\nXX.XX\n.....\n"; return;}
    if (n==15){cout<<"2 7\n.X.X.X.\n.......\n"; return;}
    memset(a,0,sizeof(a));
    if (n%8==0){
        int k=n/8;
        for (int i=1;i<=24;i+=2)
        { if (k==0) break;
            for (int j=2;j<24;j+=2){
                a[i][j]=1;
                k--;
                if (k==0) break;
            }
        }
    }
    else if (n%8==1){
        a[0][0]=a[1][0]=a[2][0]=1;
        n-=9;
        int k=n/8;
        for (int i=1;i<=24;i+=2)
        {
            if (k==0) break;
            for (int j=2;j<24;j+=2)
            {
                a[i][j]=1;
                k--;
                if (k==0) break;
            }
        }
    }
    else if (n%8==2){
        a[1][0]=a[3][0]=1;
        n-=10;
        int k=n/8;
        for (int i=1;i<=24;i+=2)
        {
            if (k==0) break;
            for (int j=2;j<24;j+=2)
            {
                a[i][j]=1;
                k--;
                if (k==0) break;
            }
        }
    }
    else if (n%8==3){
        a[0][0]=1;
        n-=3;
        int k=n/8;
        for (int i=1;i<=24;i+=2)
        {
            if (k==0) break;
            for (int j=2;j<24;j+=2)
            {
                a[i][j]=1;
                k--;
                if (k==0) break;
            }
        }
    }
    else if (n%8==4){
        a[0][0]=a[1][0]=1; a[24][0]=a[23][0]=1;
        n-=12;
        int k=n/8;
        for (int i=1;i<=24;i+=2)
        {
            if (k==0) break;
            for (int j=2;j<24;j+=2)
            {
                a[i][j]=1;
                k--;
                if (k==0) break;
            }
        }
    }
    else if (n%8==5){
        a[1][0]=1;
        n-=5;
        int k=n/8;
        for (int i=1;i<24;i+=2)
        {
            if (k==0) break;
            for (int j=2;j<24;j+=2)
            {
                a[i][j]=1;
                k--;
                if (k==0) break;
            }
        }
    }
    else if (n%8==6){
        a[0][0]=a[1][0]=1;
        n-=6;
        int k=n/8;
        for (int i=1;i<=24;i+=2)
        {
            if (k==0) break;
            for (int j=2;j<24;j+=2)
            {
                a[i][j]=1;
                k--;
                if (k==0) break;
            }
        }
    }
    else if (n%8==7){
        a[1][0]=a[3][0]=a[5][0]=1;
        n-=15;
        int k=n/8;
        for (int i=1;i<=23;i+=2)
        {
            if (k==0) break;
            for (int j=2;j<24;j+=2)
            {
                a[i][j]=1;
                k--;
                if (k==0) break;
            }
        }
    }
    cout<<"25 25\n";
    for (int i=0;i<=24;i++){
     for (int j=0;j<=24;j++){
         if (a[i][j]) cout<<"X"; else cout<<".";
     }
     cout<<"\n";
    }
}
int main(){
    int T;
    //freopen("1.in","w",stdout);
    //T=1001;
    //cout<<"1001\n";
    cin>>T;
    while (T--) solve();

}