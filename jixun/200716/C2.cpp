#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N][N];
int ans[N][N];
int res;
struct node{
    int id;
    int val;
    bool operator < (const node &a) const{
        return val<a.val;
    }
};
priority_queue <node> q;



int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)
            if (!a[i][j])
                for (int k=1;k*i<=n && k*j<=m;k++) a[i*k][j*k]=i*j*k;
    }

    for (int i=1;i<=n;i++){     for (int j=1;j<m;j++) cout<<a[i][j]; cout<<a[i][m]<<endl;}

    for (int i=1;i<=n;i++){
        while (!q.empty()) q.pop();
        cout<<"success"<<endl;
    for (int j=1;j<k;j++){
        node tmp; tmp.id=j; tmp.val=a[i][j];
        q.push(tmp);
    }
    for (int j=k;j<=m;j++){
        node tmp;
        tmp.id=j; tmp.val=a[i][j];
        q.push(tmp);
        while (q.top().id<j-k+1) q.pop();
        tmp=q.top();
        ans[i][j]=tmp.val;
    }
    }

    for (int j=1;j<=m-k+1;j++){
        cout<<"j="<<j<<endl;
        while (!q.empty()) q.pop();
        for (int i=1;i<k;i++){
            node tmp;
            tmp.id=i; tmp.val=ans[i][j];
            q.push(tmp);
        }
        for (int i=k;i<=n;i++){
            node tmp;
            tmp.id=i; tmp.val=ans[i][j];
            while (q.top().id<i-k+1) q.pop();
            tmp=q.top();
            res+=tmp.id;
        }
    }
    cout<<res<<endl;
    return 0;
}