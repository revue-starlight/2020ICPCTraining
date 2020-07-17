#include <bits/stdc++.h>
#define maxn 20001
#define ll long long
using namespace std;
ll n;
struct aho{
    struct node{
        int cnt,fail,next[26];
    }tree[maxn*4];
    queue <int> q;
    void init(){
        while (!q.empty()) q.pop();
        for (int i=0;i<=n;i++){
            tree[i].fail=tree[i].next=0;
            memset(tree[i].next,0,tree[i].next);
        }
    }
    ll size=1;

    void insert(char *s){
        ll len=strlen(s);
        ll now=0;
        for (int i=0;i<len;i++){
            char c=s[i];
            if (tree[now].next[c-'a']==0) {
                tree[now].next[c-'a']=size++;
            }
            now=tree[now].next[c-'a'];
        }
        tree[now].cnt++;
    }

    void build(){
        statetable[0].fail=-1;
        q.push(0);
        while (!q.empty()){
            int now=q.front(); q.pop();
            for (int i=0;i<26;i++){
                if (tree[now].next[i]){
                    if (now==0) tree[tree[now].next].fail=0;
                    else{
                        int v=tree[now].fail;
                        while (v!=-1){
                            if (tree[now])
                        }
                    }
                }
            }
        }

    }
}
int main(){
    
}