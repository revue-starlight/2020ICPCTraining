#include <bits/stdc++.h>
using namespace std;
#define maxn 10001
#define maxm 1000006
int a[maxn],b[maxm],nxt[maxm],n,m;

void getnxt(){
    nxt[0]=-1; int k=-1,i=0;
    while (i<m){
        if (k==-1 || b[k]==b[i]){
            k++,i++; nxt[i]=k;
        }
        else
        {
            k=nxt[k];
        }
    }
}

int kmp(){
    int i=0,j=0;
    while (i<n){
        if (j==-1 || a[i]==b[j]){
            j++,i++;
        }
        else j=nxt[j];
        if (j==m) return i-j;
    }
    return -1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        cin>>n>>m;
        for (int i=0;i<n;i++)
            cin>>a[i];
        for (int i=0;i<m;i++)
            cin>>b[i];
        getnxt();
        cout<<kmp()+1<<endl;
    }
}