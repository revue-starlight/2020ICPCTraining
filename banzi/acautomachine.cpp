#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+100;
queue <int> q;
//太慢了我人都傻了
struct acautomachine{
    struct abc{
        int fail,last,cnt;
        int next[26]; 
    }tree[maxn];
    int tot;
    inline void init(){
        tot=0;
        while (!q.empty()) q.pop();
        tree[0].fail=-1;
        memset(tree[0].next,0,sizeof(tree[0].next));
    }

    void insert(string s){
        int len=s.length();
        int now=0;
        for (int i=0;i<len;i++){
            char ch=s[i];
            if (tree[now].next[ch-'a']==0) {
                tree[now].next[ch-'a']=++tot;
                memset(tree[tot].next,0,sizeof(tree[tot].next));
                tree[tot].fail=tree[tot].cnt=tree[tot].last=0;
                }
            now=tree[now].next[ch-'a'];
        }
        tree[now].cnt++;
    }

    void build(){
        for (int i=0;i<26;i++){
            if (tree[0].next[i]) q.push(tree[0].next[i]);
        }
        while (!q.empty()){
            int x=q.front(); q.pop();
            for (int i=0;i<26;i++)
            {
                if (!tree[x].next[i]) {tree[x].next[i]=tree[tree[x].fail].next[i];}
                else
                {
                    q.push(tree[x].next[i]);
                    tree[tree[x].next[i]].fail=tree[tree[x].fail].next[i];
                    tree[tree[x].next[i]].last=tree[tree[x].next[i]].cnt?tree[tree[x].next[i]].fail:tree[tree[tree[x].next[i]].fail].last;
                }
            }    
        }
    }

    int get(int x){
        int res=0;
        while (x){
            res+=tree[x].cnt;
            tree[x].cnt=0;
            x=tree[x].last;
        }
        return res;
    }
    int match(string s){
        int ans=0;
        int len=s.length();
        int now=0;
        for (int i=0;i<len;i++){
            char ch=s[i];
            now=tree[now].next[ch-'a'];
            if (tree[now].cnt)
                ans+=get(now);
        }
        return ans;
    }
}Aho;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        string s;
        Aho.init();
        for (int i=0;i<n;i++){
            cin>>s;
            Aho.insert(s);
        }
        Aho.build();
        cin>>s;
        cout<<Aho.match(s)<<endl;
    }
    return 0;
}