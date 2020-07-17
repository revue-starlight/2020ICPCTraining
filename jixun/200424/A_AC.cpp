#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define maxn 1000006
#define maxtot 500005

struct Aho{
    struct state{
        int next[26];
        int cnt,fail;
    }statetable[maxtot];

    int size;

    std::queue<int> que;

    void init(){
        while (que.size()) que.pop();
        for (int i=0;i<maxtot;i++){
            memset(statetable[i].next,0,sizeof(statetable[i].next));
            statetable[i].fail=statetable[i].cnt=0;
        }
        size=1;
    }
    
    void insert(char *S){
        int n=strlen(S);
        int now=0;
        for (int i=0;i<n;i++){
            char c=S[i];
            if (!statetable[now].next[c-'a']) 
                statetable[now].next[c-'a']=size++;
            now=statetable[now].next[c-'a'];
        }
        statetable[now].cnt++;
    }

    void build(){
        statetable[0].fail=-1;
        que.push(0);

        while (que.size()){
            int u=que.front();
            que.pop();
            for (int i=0;i<26;i++){
                if (statetable[u].next[i]){
                    if (u==0) statetable[statetable[u].next[i]].fail=0;
                    else{
                        int v=statetable[u].fail;
                        while (v!=-1){
                            if (statetable[v].next[i]){
                                statetable[statetable[u].next[i]].fail=statetable[v].next[i];
                                break;
                            }
                            v=statetable[v].fail;
                        }
                        if (v==-1) statetable[statetable[u].next[i]].fail=0;
                    }
                    que.push(statetable[u].next[i]);
                }
            }
        }
    }
 
    int Get(int u){
    int res=0;
    while (u){
        res=res+statetable[u].cnt;
        statetable[u].cnt=0;
        u=statetable[u].fail;
    }
    return res;
    }

    int match(char *s){
        int n=strlen(s);
        int res=0,now=0;
        for (int i=0;i<n;i++){
            char c=s[i];
            if (statetable[now].next[c-'a'])
                now=statetable[now].next[c-'a'];
            else{
                int p=statetable[now].fail;
                while (p!=-1 && statetable[p].next[c-'a']==0) p=statetable[p].fail;
                if (p==-1) now=0;// important
                else now=statetable[p].next[c-'a'];
            }
            if (statetable[now].cnt) 
                res= res+Get(now);
        }
        return res;
    }
}aho;

int T;

int N;

char S[maxn];

int main(){
    scanf("%d",&T);
    while (T--){
        aho.init();
        scanf("%d",&N);
        for (int i=0;i<N;i++){
            scanf("%s",S);
            aho.insert(S);
        }
        aho.build();
        scanf("%s",S);
        printf("%d\n",aho.match(S));
    }
    return 0;
}