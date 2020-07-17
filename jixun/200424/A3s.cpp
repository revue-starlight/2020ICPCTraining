#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+5;

struct Aho{    
    int nxt[maxn][26],fail[maxn],val[maxn],tot;
    void init(){
        tot=0;
        memset(val,0,sizeof(val));
        memset(nxt,0,sizeof(nxt));
        memset(fail,0,sizeof(fail));                                                                                                            
    }
    void insert(const string &s){
        int u=0;
        for(auto x:s){
            int i=x-'a';
            if(!nxt[u][i])nxt[u][i]=++tot;
            u=nxt[u][i];
        }
        val[u]++;//number of endings++
    }
    void build(){
        queue<int> q;
        fail[0]=-1;
        q.push(0);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0;i<26;++i){
                if(!nxt[u][i])continue;
                if(u==0)fail[nxt[u][i]]=0;
                else{
                    int v=fail[u];
                    while(v!=-1){
                        if(nxt[v][i]){
                            fail[nxt[u][i]]=nxt[v][i];
                            break;
                        }
                        v=fail[v];
                    }
                    if(v==-1)fail[nxt[u][i]]=0;
                }
                q.push(nxt[u][i]);
            }
        }
    }
    int getans(int u){
        int res=0;
        while(u){
            res+=val[u];
            val[u]=0;
            u=fail[u];
        }
        return res;
    }
    int match(const string &s){
        int u=0,res=0;
        for(auto x:s){
            int i=x-'a';
            if(nxt[u][i])u=nxt[u][i];
            else{
                int p=fail[u];
                while(~p&&!nxt[p][i])p=fail[p];
                if(p==-1)p=0;
                else u=nxt[p][i];
            }
            res+=getans(u);//本质上是穷举结尾跳跃式寻找后缀，在模式串高度重复时单次getans复杂度会退化到O(n)
        }
        return res;
    }
}aho;

int T,n;
string s;

int main(){
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n;
        aho.init();
        while(n--){
            cin>>s;
            aho.insert(s);
        }
        aho.build();
        cin>>s;
        cout<<aho.match(s)<<endl;
    }
}