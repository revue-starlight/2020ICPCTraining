#include <bits/stdc++.h>
using namespace std;
const int maxn=6e5+10;
const int maxm=1e5+10;
queue <int> q;
int ans[maxm];
int mem[maxm];
struct ACautomation{
    struct Node{
    int fail,cnt,last,next[26],len;
    vector < pair<int,int> > id; //id,typ
    }tree[maxn];
    int tot;
    void init(){
        tree[0].cnt=tree[0].last=0;
        for (int i=0;i<26;i++) tree[0].next[i]=0;
        int tot=0;
        tree[0].fail=-1;
        while (!q.empty()) q.pop();
        tree[0].id.clear();
    }

    void insert(string s,int typ,int id){
        int len=s.length();
        int now=0;
        for (int i=0;i<len;i++){
            char ch=s[i]-'a';
            if (!tree[now].next[i]) {
                tree[now].next[i]=++tot;
                for (int i=0;i<26;i++) tree[tot].next[i]=0;
                tree[tot].fail=tree[tot].last=tree[tot].cnt=tree[tot].cnt=0;
                tree[tot].id.clear();

            }
            now=tree[now].next[i];
        }
        pair <int,int> tmp;
        tmp.first=id; tmp.second=typ;
        tree[now].id.push_back(tmp);
        tree[now].len=len;
        mem[id]=ans[id]=0;
        tree[now].cnt++;
    }

    void build(){
        int now=0;
        for (int i=0;i<26;i++) if (tree[0].next[i]!=0) q.push(tree[0].next[i]);
        while (!q.empty()){
            int x=q.front(); q.pop();
            for (int i=0;i<26;i++)
                if (!tree[x].next[i]) tree[x].next[i]=tree[tree[x].fail].next[i];
                else{
                    q.push(tree[x].next[i]);
                    tree[tree[x].next[i]].fail=tree[tree[x].fail].next[i];
                    tree[tree[x].next[i]].last=tree[tree[tree[x].next[i]].fail].cnt?tree[tree[x].next[i]].fail:tree[tree[tree[x].next[i]].fail].last;

                }
        }
    }
    void get(int x,int pos){
        while (x){
            int len=tree[x].id.size();
            for (int i=0;i<len;i++){
                pair <int,int> tmp;
                tmp=tree[x].id[i];
                if (tmp.second==1){
                    if (mem[tmp.first]-pos>=tree[x].len){
                        mem[tmp.first]=pos;
                        ans[tmp.first]++;
                    }
                }
                else ans[tmp.first]++;
            }
            x=tree[x].last;
        }
    }
    void match(string s){
        int len=s.length();
        int now=0;
        for (int i=0;i<len;i++){
            char ch=s[i];
            now=tree[now].next[i];
            if (tree[now].cnt) get(now,i);
        }
    }
}AC;
int main(){
    string ss;
    int tot=0;
    while (cin>>ss){
        tot++;
        int n;
        cin>>n;
        AC.init();
        for (int i=1;i<=n;i++){
            int typ;
            string s;
            cin>>typ;
            cin>>s;
            AC.insert(s,typ,i);
        }
        AC.match(ss);
        cout<<"Case "<<tot<<endl;
        for (int i=1;i<=n;i++){
            cout<<ans[i]<<endl;
        }
        cout<<endl;
    }
}