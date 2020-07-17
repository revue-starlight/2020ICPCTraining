#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#define maxn 1000006
#define maxtot 500005
using namespace std;
struct acmachine{
    struct state{
        int next[26],cnt,fail;
    }statetable[maxtot];
    queue <int> que;
    int size;
    void init(){
        while (!que.empty()) que.pop();
        for (int i=0;i<maxtot;i++){
            memset(statetable[i].next,0,sizeof(statetable[i].next));
        }
        size=1;
    }

    void insert(char *s){
        int n=strlen(s),now=0;
        for (int i=0;i<n;i++){
            char c=s[i];
            if (statetable[now].next[c-'a']==0) statetable[now].next[c-'a']=size++;
            now=statetable[now].next[c-'a'];
        }
        statetable[now].cnt++;
    }

    void build(){
        statetable[0].fail=-1;
        que.push(0);
        while (!que.empty()){
            int u=que.front();
            que.pop();
            for (int i=0;i<26;i++){
                if (statetable[u].next[i]){ //遍历u节点的子节点
                    if (!u) statetable[statetable[u].next[i]].fail=0;//u是根，u的儿子的fail指向0
                        else {
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
    int get(int u){
        int res=0;
        while (u){
            res+=statetable[u].cnt;
            statetable[u].cnt=0; //匹配以后不能再匹配了，让他消失
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
                now=statetable[now].next[c-'a'];//如果当前状态能找到，就走他咯
            else{
                int p=statetable[now].fail;
                while (p!=-1 && statetable[p].next[c-'a']==0) p=statetable[p].fail;
                if (p==-1) now=0;
                    else now=statetable[p].next[c-'a'];
            }
            if (statetable[now].cnt)
                res+=get(now);
        }
        return res;
    }
}aho;

int main(){
    int t;
    int n;
    char s[maxn];
    scanf("%d",&t);
    while (t--){
        aho.init();
        scanf("%d",&n);
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