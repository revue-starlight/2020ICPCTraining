#include <bits/stdc++.h>
using namespace std;
const int maxn=6e5+10;
queue <int> q;

struct acautomation{
    struct treee{
        int fail,cnt,last,next[26];
    }tree[maxn];
    int tot;
    
    void init(){
        tot=0;
        memset(tree[0].next,0,sizeof(tree[0].next));
        tree[0].cnt=tree[0].last=0;
        tree[0].fail=-1;
        while (!q.empty()) q.pop();
    }

    void insert(string s){
        int len=s.length();
        int now=0;
        for (int i=0;i<len;i++){
            char ch=s[i];
            if (tree[now].next[ch-'a']==0) {
                tree[now].next[ch-'a']=++tot;
                memset(tree[tot].next,0,sizeof(tree[tot].next));
                tree[tot].cnt=tree[tot].fail=tree[tot].last=0;    
            }
            now=tree[now].next[ch-'a'];
        }
        tree[now].cnt++;
    }

    void build(){
        for (int i=0;i<26;i++)
            if (tree[0].next[i]) q.push(tree[0].next[i]);
        while (q.empty()){
            int x=q.front(); q.pop();
            for (int i=0;i<26;i++)
                if (!tree[x].next[i]) tree[x].next[i]=tree[tree[x].fail].next[i];
                else
                {
                    tree[tree[x].next[i]].fail=tree[tree[x].fail].next[i];
                    q.push(tree[x].next[i]);
                    if (tree[tree[tree[x].next[i]].fail].cnt) 
                        tree[tree[x].next[i]].last=tree[tree[x].next[i]].fail;
                    else
                        tree[tree[x].next[i]].last=tree[tree[tree[x].next[i]].fail].last;
        }  
    }
}Aho;

int main(){
    string s;
    while (cin>>s){
        int n;
        cin>>n;
        Aho.init();
        for (int i=1;i<=n;i++){

        }
    }
}