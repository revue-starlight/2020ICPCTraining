#include <bits/stdc++.h>
using namespace std;
#define ll long long
queue <int> q;
int ans[1004];
string ss[1004];
const int maxn=6e4+50;
struct ACautomation{
    struct node{
        int last,fail,cnt,id;
        int next[26];
    }tree[maxn];
    int tot;
    void init(){
        tree[0].last=tree[0].fail=tree[0].cnt=0;
        memset(tree[0].next,0,sizeof(tree[0].next));   
        tot=0;
        tree[0].fail=-1;
        while (!q.empty()) q.pop();
    }

    void insert(string s,int id){
        int len=s.length();
        int now=0;
        for (int i=0;i<len;i++){
            char ch=s[i];
            if (tree[now].next[ch-'A']==0) 
            {
                tree[now].next[ch-'A']=++tot;
                memset(tree[tot].next,0,sizeof(tree[tot].next));
                tree[tot].last=tree[tot].fail=tree[tot].cnt=0;
            }
            now=tree[now].next[ch-'A'];
        }
        tree[now].cnt++;
        tree[now].id=id;
    }

    void build(){
        for (int i=0;i<26;i++){
            if (tree[0].next[i]) q.push(tree[0].next[i]);
        }
        while (!q.empty()){
            int x=q.front(); q.pop();
            for (int i=0;i<26;i++){
                if (!tree[x].next[i]) tree[x].next[i]=tree[tree[x].fail].next[i];
                else{
                    q.push(tree[x].next[i]);
                    tree[tree[x].next[i]].fail=tree[tree[x].fail].next[i];
                    tree[tree[x].next[i]].last=tree[tree[x].next[i]].cnt?tree[tree[x].next[i]].fail:tree[tree[tree[x].next[i]].fail].last;
                }
            }
        }
    }

    void get(int x){
        int res=0;
        while (x){
            if (tree[x].cnt>0) ans[tree[x].id]+=tree[x].cnt;
            x=tree[x].last;
        }
    }
    void match(string s){
        int len=s.length();
        int now=0;
        for (int i=0;i<len;i++){
            char ch=s[i];
            if (ch-'A'<26 && ch-'A'>=0) now=tree[now].next[ch-'A'];
            else now=0;
            if (tree[now].cnt) get(now);
        }
    }
}Aho;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n){
    memset(ans,0,sizeof(ans));
    Aho.init();
    for (int i=1;i<=n;i++){
        cin>>ss[i];
        Aho.insert(ss[i],i);
    }
    Aho.build();
    string s;
    cin>>s;
    Aho.match(s);
    for (int i=1;i<=n;i++){
        if (ans[i]>0){
            cout<<ss[i]<<": "<<ans[i]<<endl;
        }
    }
    }
    return 0;
}