#include <bits/stdc++.h>
using namespace std;
const int maxn=10000;
int n;
struct Aho{
    struct node{
        int next[26],fail,cnt;
    }tree[maxn];
    int tot=0;
    void init(){
        tot=0;
        for (int i=1;i<=n;i++) {
            tree[i].cnt=tree[i].fail=0;
            memset(tree[i].next,0,sizeof(tree[i].next));
        }
    }
    
    void insert(string s){
        int len=s.length();
        int p=0;
        for (int i=0;i<len;i++){
            char ch=s[i];
            if (tree[p].next[ch-'a']==0)
                tree[p].next[ch-'a']=++tot;
            p=tree[p].next[ch-'a'];
        }
        tree[p].cnt++;
    }

    void build(){
        queue <int> q; while (!q.empty()) q.pop();
        for (int i=1;i<=26;i++){
            if (tree[0].next[i]) q.push(i);
        }
     }
}

void solve(){
    cin>>n;
    Aho x;
    while (n--){
        string s;
        cin>>s;
        x.insert(s);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        solve();
    }
}