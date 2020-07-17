#include <iostream>
#include <queue>
using namespace std;
#define maxn 200001
struct Aho{
    struct state{
        int next[26],fail,cnt;
    }tree[maxn];
    int size;
    queue <int> q;
    void init(){
        while (!q.empty()) q.pop();
        for (int i=1;i<=maxn;i++)
        {memset(tree[i].next,0,sizeof(tree[i].next)); tree[i].fail=tree[i].cnt=0;}
        size=1;
    }
    void insert(char* s){
        int len=strlen(s);
        int now=0;
        for (int i=0;i<len;i++){
            char c=s[i];
            if (tree[now].next[c-'a']==0) tree[now].next[c-'a']=size++;
            now=tree[now].next[c-'a'];
        }
        tree[now].cnt++;
    }
    
    void build(){
        tree[0].fail=-1;
        for (int i=0;i<26;i++) if (tree[0].next[i]) q.push(tree[0].next[i]);
        while (!q.empty()){
            int u=q.front(); q.pop();
            for (int i=0;i<26;i++) { 
                if (tree[u].next[i]==0) {tree[u].next[i]=tree[tree[u].fail].next[i]; continue;}
                else{
                    q.push(tree[u].next[i]);
                    int v=tree[u].fail;
                    while (v!=-1 && tree[v].next[i]==0) v=tree[v].fail;
                    if (v==-1) tree[tree[u].next[i]].fail=0;
                        else tree[tree[u].next[i]].fail=tree[v].next[i];
                    tree[tree[u].next[i]].cnt+=tree[tree[tree[u].next[i]].fail].cnt;
                }
            }
        }
    }
    int match(char *S){
        int len=strlen(S);
        int now=0,res=0;
        for (int i=0;i<len;i++){
            char c=s[i];
            now=tree[now].next[c-'a'];
            res+=tree[now].cnt;
        }
        return res;
    }

}aho;
int T;
char s[maxn];
int n;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>T;
    while (T--){
        cin>>n;
        aho.init();
        for (int i=0;i<n;i++) {cin>>s; aho.insert(s);}
        aho.build();
        cin>>s;
        cout<<aho.match(s)<<endl;
    }
    return 0;
}