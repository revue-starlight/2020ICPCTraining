#include <bits/stdc++.h>
using namespace std;
#define max_tot 200001
#define maxn 1000006
struct Aho{
    struct state{
        int fail,cnt,next[26];
    }tree[max_tot];
    
    queue <int> q;

    int size;

    void init(){
        while (!q.empty()) q.pop();
        for (int i=1;i<=max_tot;i++) {
            memset(tree[i].next,0,sizeof(tree[i].next));
            tree[i].fail=tree[i].cnt=0;
        }
        size=1;
    }

    void insert(char *s){
        int len=strlen(s);
        int now=0;
        for (int i=0;i<len;i++){
            int c=s[i];
            if (tree[now].next[c-'A']==0) tree[now].next[c-'A']=size++;
            now=tree[now].next[c-'A'];
        }
        tree[now].cnt++;
    }

    void build(){
        tree[0].fail=-1;
        for (int i=0;i<26;i++) if (tree[0].next[i]) q.push(tree[0].next[i]);
        while (!q.empty()){
            int u=q.front(); q.pop();
            for (int i=0;i<26;i++){
                if (tree[u].next[i]==0) {tree[u].next[i]=tree[tree[u].fail].next[i]; continue;}
                int v=tree[u].fail;
                while (v!=-1 && tree[v].next[i]==0) v=tree[v].fail;
                if (v==-1) 
                    tree[tree[u].next[i]].fail=0; 
                else 
                    tree[tree[u].next[i]].fail=tree[v].next[i-'A'];
            }
        } 
    }

    int match(char *S){
        int len=strlen(S);
        int now=0;
        for (int i=0;i<len;i++){
            char c=s[i];
            if (s[i]<'A' || s[i]>'Z') {now=0; continue;}
            now=tree[now].next[c-'A'];
            if (tree[now].cnt)
        }
    }
}
int main(){
    
}