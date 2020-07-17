#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll Maxm=5e5+10;
const ll Maxn=1e6+10;
queue <int> q;
struct Aho{
    struct node{
        int next[26],fail,cnt;
    }tree[Maxm];
    void init(){
        for (int i=0;i<=Maxm;i++){
            memset(tree[i].next,0,sizeof(tree[i].next));
            tree[i].fail=tree[i].cnt=0;
        }
        tree[0].fail=-1;
        while (!q.empty()) q.pop();
    }
    int size=0;
    void insert(string s){
        int len=s.length(),now=0;
        for (int i=0;i<len;i++){
            char ch=s[i]; 
            if (!tree[now].next[ch-'a']) tree[now].next[ch-'a']=++size;
            now=tree[now].next[ch-'a'];
        }
        tree[now].cnt++;
    }
    void build(){
        for (int i=0;i<26;i++) 
            if (tree[0].next[i]) 
                q.push(tree[0].next[i]);
        
        while (!q.empty()){
            int x=q.front();
            q.pop();
            for (int i=0;i<26;i++)
                if (tree[x].next[i]) {
                    q.push(tree[x].next[i]);
                int now=tree[x].fail;
                while (now!=-1 && !tree[now].next[i]){
                    now=tree[now].fail;
                }
                if (now==-1) tree[tree[x].next[i]].fail=0; 
                    else tree[tree[x].next[i]].fail=tree[now].next[i];
                } 
        }
    }

    int Get(int x){
        int res=0;
        while (x){
            res+=tree[x].cnt; tree[x].cnt=0;
            x=tree[x].fail;
        }
        return res;
    }
    int match(string s){
        int len=s.length();
        int now=0;
        int res=0;
        for (int i=0;i<len;i++){
            char ch=s[i];
            if (tree[now].next[ch-'a']) now=tree[now].next[ch-'a'];
            else{
                while (now!=-1 && !tree[tree[now].fail].next[ch-'a']) now=tree[now].fail;
                if (now==-1) now=0; else now=tree[tree[now].fail].next[ch-'a'];
            }
            if (tree[now].cnt)  res=res+Get(now);
        }
        return res;
    }
}aho;

int main(){
    int T;
    cin>>T;
    while (T--){
        aho.init();
        int n;
        cin>>n;
        string s;
        for (int i=1;i<=n;i++){
            cin>>s;
            aho.insert(s);
        }
        aho.build();
        cin>>s;
        cout<<aho.match(s)<<endl;
    }
}
