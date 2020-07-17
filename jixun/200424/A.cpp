#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000006
#define MAXT 500005
struct Aho{

    struct State{
        int cnt,fail,next[26];
    }tree[MAXT];

    int size;
    queue <int> q;

    void init(){
        while (!q.empty()) q.pop();
        for (int i=0;i<MAXT;i++){
            memset(tree[i].next,0,sizeof(tree[i].next));
            tree[i].cnt=tree[i].fail=0;
        }
        size=1;
    }

    void insert(char* s){
        int len=strlen(s),now=0;
        for (int i=0;i<len;i++){
            char c=s[i];
            if (tree[now].next[c-'a']==0) tree[now].next[c-'a']=size++;
            now=tree[now].next[c-'a'];
        }
        tree[now].cnt++;
    }

    void build(){
        tree[0].fail=-1;
        q.push(0);
        while (!q.empty()){
            int u=q.front(); q.pop();
            for (int i=0;i<26;i++){
                if (tree[u].next[i]!=0){
                    if (u==0) tree[tree[u].next[i]].fail=0;
                    else{
                        int v=tree[u].fail;
                        while (v!=-1){
                            if (tree[v].next[i]){
                                tree[tree[u].next[i]].fail=tree[v].next[i];
                                break;
                            }
                            v=tree[v].fail;
                        }
                        if (v==-1) tree[tree[u].next[i]].fail=0;
                    }
                    q.push(tree[u].next[i]);
                }
            }
        }
    }

    int get(int now){
        int res=0;
        while (now){
            res+=tree[now].cnt;
            tree[now].cnt=0;
            now=tree[now].fail;
        }
        return res; 
    }

    int match(char *s){
        int len=strlen(s);
        int res=0,now=0;
        for (int i=0;i<len;i++){
            char c=s[i];
            if (tree[now].next[c-'a'])
                now=tree[now].next[c-'a'];
            else{
                int p=tree[now].fail;
                while (p!=-1 && tree[p].next[c-'a']==0)
                    p=tree[p].fail;
                if (p==-1) now=0;
                    else now=tree[p].next[c-'a'];
            }
            if (tree[now].cnt) res+=get(now);
        }
        return res;
    }
}aho;
int main(){
    int t;
    scanf("%d",&t);
    while (t--){
        aho.init();
        int n;
        scanf("%d",&n);
        char s[10001];
        for (int i=0;i<n;i++){
            scanf("%s",s);
            aho.insert(s);
        }
        aho.build();
        scanf("%s",s);
        printf("%d\n",aho.match(s));
    }
    return 0;
}