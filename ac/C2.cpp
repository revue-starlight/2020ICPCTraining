#include <bits/stdc++.h>
using namespace std;
const int N=6e5+100;
const int M=1e5+10;
int ans[N][2];
int lenn[M];
int op[M];

struct ACAUTOMATION{
    int next[N][26],fail[N],pos[N],last[N],node[N];
    int tot;
    void init(){
        for (int i=0;i<26;i++) next[0][i]=0;
        last[0]=fail[0]=0;
        tot=0;
    }
    
    inline void insert(char* s,int type,int id){
        int len=strlen(s);
        int now=0;
        for (int i=0;i<len;i++){
            char ch=s[i];
            if (next[now][ch-'a']==0) {
                next[now][ch-'a']=++tot;
                fail[tot]=last[tot]=0;
                for (int i=0;i<26;i++) next[tot][i]=0;
            }
            now=next[now][ch-'a'];
            pos[now]=i;
        }
        node[id]=now;
    }

    inline void build(){
        int now=0;
        queue <int> q;
        for (int i=0;i<26;i++) if (next[now][i]) q.push(next[now][i]);
        while (!q.empty()){
            int x=q.front(); q.pop();
            for (int i=0;i<26;i++){
                if (!next[x][i]) next[x][i]=next[fail[x]][i];
                else{
                    q.push(next[x][i]);
                    fail[next[x][i]]=next[fail[x]][i];
                    /*if (cnt[fail[next[x][i]]])
                        last[next[x][i]]=fail[next[x][i]];
                    else
                        last[next[x][i]]=last[fail[next[x][i]]];*/

                }
            }
        }
    }

    /*inline void get_ans(int pos,int pos_now){
        while (pos){
            int size=vec[pos].size();
            for (int i=0;i<size;i++){
                if (vec[pos][i].first==0){
                    ans[vec[pos][i].second]++;
                }
                else{
                    if (pos_now-mem[vec[pos][i].second]>=lenn[vec[pos][i].second])
                    {
                        mem[vec[pos][i].second]=pos_now;
                        ans[vec[pos][i].second]++;
                    }
                }
            }
            pos=last[pos];
        }
    }*/
    inline void match(char* s){
        int len=strlen(s);
        int now=0;
        for (int i=0;s[i];i++){
            char ch=s[i];
            int tmp=next[now][ch-'a'];
            while (tmp){
                ans[tmp][0]++;
                if (i-last[tmp]>=pos[tmp]){
                    last[tmp]=i;
                    ans[tmp][1]++;
                }
                tmp=fail[tmp];
            }
        }
    }
}AC;
char ss[M];
int main(){
    int T;
    while (~scanf("%s",ss)){
        T++;
        int n;
        scanf("%d",&n);
        AC.init();
        for (int i=1;i<=n;i++){
            ans[i][0]=ans[i][1]=0;
            char s[M]; int x;
            scanf("%d %s",&op[i],s);
            lenn[i]=strlen(s);
            AC.insert(s,x,i);
        }
        AC.build();
        AC.match(ss);
        printf("Case %d\n",T);
        for (int i=1;i<=n;i++) printf("%d\n",ans[i][op[i]]);
        cout<<endl;
    }
    return 0;
}