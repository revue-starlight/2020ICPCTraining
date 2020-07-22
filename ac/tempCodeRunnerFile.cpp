#include <bits/stdc++.h>
using namespace std;
const int N=6e5+100;
const int M=1e5+10;
queue <int> q;
int mem[M];
int ans[M];
int lenn[M];

struct ACAUTOMATION{
    struct Node{
        int last,fail,next[26],cnt;
        vector <pair<int,int> > vec; //type,id
    }tree[N];
    int tot;
    void init(){
        for (int i=0;i<26;i++) tree[0].next[i]=0;
        tree[0].last=tree[0].fail=tree[0].cnt=0;
        tot=0;
    }
    
    inline void insert(string s,int type,int id){
        int len=s.length();
        int now=0;
        for (int i=0;i<len;i++){
            char ch=s[i];
            if (tree[now].next[ch-'a']==0) {
                tree[now].next[ch-'a']=++tot;
                tree[tot].cnt=tree[tot].fail=tree[tot].last=0;
                for (int i=0;i<26;i++) tree[tot].next[i]=0;
            }
            now=tree[now].next[ch-'a'];
        }
        pair <int,int> tmp;
        tmp.first=type; tmp.second=id;
        tree[now].vec.push_back(tmp);
        tree[now].cnt++;
    }

    void build(){
        int now=0;
        for (int i=0;i<26;i++) if (tree[now].next[i]) q.push(tree[now].next[i]);
        while (!q.empty()){
            int x=q.front(); q.pop();
            for (int i=0;i<26;i++){
                if (!tree[x].next[i]) tree[x].next[i]=tree[tree[x].fail].next[i];
                else{
                    q.push(tree[x].next[i]);
                    tree[tree[x].next[i]].fail=tree[tree[x].fail].next[i];
                    if (tree[tree[tree[x].next[i]].fail].cnt)
                        tree[tree[x].next[i]].last=tree[tree[x].next[i]].fail;
                    else
                        tree[tree[x].next[i]].last=tree[tree[tree[x].next[i]].fail].last;
                }
            }
        }
    }

    void get_ans(int pos,int pos_now){
        while (pos){
            int size=tree[pos].vec.size();
            for (int i=0;i<size;i++){
                if (tree[pos].vec[i].first==0){
                    ans[tree[pos].vec[i].second]++;
                }
                else{
                    if (pos_now-mem[tree[pos].vec[i].second]>=lenn[tree[pos].vec[i].second])
                    {
                        mem[tree[pos].vec[i].second]=pos_now;
                        ans[tree[pos].vec[i].second]++;
                    }
                }
            }
            pos=tree[pos].last;
        }
    }
    void match(string s){
        int len=s.length();
        int now=0;
        for (int i=0;i<len;i++){
            char ch=s[i];
            now=tree[now].next[ch-'a'];
            if (tree[now].cnt!=0) get_ans(now,i);
        }
    }
};

int main(){
    int T;
    string ss;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin>>ss){
        ACAUTOMATION AC;
        T++;
        int n;
        cin>>n;
        AC.init();
        for (int i=1;i<=n;i++) {ans[i]=0; mem[i]=-1;}
        for (int i=1;i<=n;i++){
            string s; int x;
            cin>>x>>s;
            lenn[i]=s.length();
            AC.insert(s,x,i);
        }
        AC.build();
        AC.match(ss);
        cout<<"Case "<<T<<endl;
        for (int i=1;i<=n;i++) cout<<ans[i]<<endl;
        cout<<endl;
    }
    return 0;
}