#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int N=1e4+3;
const int M=1e6+3;
const int L=50+3;
struct trie{
    int ed;
    int a[26];
    int fail;
    void clear(){
    ed=fail=0;
    memset(a,0,sizeof(a));
    return;
    }
}tree[N*L]={0};
char s[M];
int cnt=0;
inline void insert(){
    int now=0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        int t=s[i]-97;
        if(!tree[now].a[t]){
            cnt++;
            tree[now].a[t]=cnt;
        tree[cnt].clear();
        }
        now=tree[now].a[t];
    }
    tree[now].ed++;
    return;
}
int q[N*L];
void getfail(){
    int r=0;
    //以下是对第一层的特殊处理 
    for(int i=0;i<26;i++){
        if(tree[0].a[i]!=0){
            tree[tree[0].a[i]].fail=0;
        r++;q[r]=tree[0].a[i];
        }
    }
    for(int l=1;l<=r;l++){
        int u=q[l];
        for(int i=0;i<26;i++){
            if(tree[u].a[i]!=0){
                tree[tree[u].a[i]].fail=tree[tree[u].fail].a[i];
        r++;q[r]=tree[u].a[i];
            }else{
                tree[u].a[i]=tree[tree[u].fail].a[i];
            }
        }
    }
    return;
}
int check(){
    int now=0,ans=0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        int t=s[i]-97;
        now=tree[now].a[t];
        for(int j=now;j&&tree[j].ed!=-1;j=tree[j].fail){
            ans+=tree[j].ed;
            tree[j].ed=-1;
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    tree[0].clear();
    cnt=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        insert();
    }
    getfail();
    cin>>s;
    cout<<check()<<endl;
    }
    return 0;
}