#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int nxt[maxn];
int a[maxn],b[maxn];
int n,m;
inline void get_nxt(){
    nxt[0]=0;
        for(int i=1,j=0;i<n;i++){
        while(a[i]!=a[j]&&j) j=nxt[j-1];
        if(a[i]==a[j]) j++;
        nxt[i]=j;
     }
}

int main(){
    int T;
    while (cin>>T){
       cin>>n>>m;
       for (int i=0;i<n;i++) cin>>a[i];   
       for (int j=0;j<m;j++) cin>>b[j];
       get_nxt();
       int t=0;
       int k=0;
       while (t<n){
           if (a[t]==b[k]) k++;
            else t=nxt[k];
            t++;
       }
    }
}