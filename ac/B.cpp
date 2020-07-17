    #include<iostream>
    #include<cstdio>
    #include<cstdlib>
    #include<string>
    #include<cstring>
    #include<cmath>
    #include<ctime>
    #include<algorithm>
    #include<utility>
    #include<stack>
    #include<queue>
    #include<vector>
    #include<set>
    #include<map>
    #define PI acos(-1.0)
    #define E 1e-9
    #define INF 0x3f3f3f3f
    #define LL long long
    const int MOD=10007;
    const int N=500000+5;
    const int dx[]= {-1,1,0,0};
    const int dy[]= {0  ,0,-1,1};
    using namespace std;
    int res[N];//记录结果
    struct AC_Automata{
        int tire[N][128];//字典树
        int val[N];//字符串结尾标记
        int fail[N];//失配指针
        int last[N];//last[i]=j表j节点表示的单词是i节点单词的后缀，且j节点是单词节点
        int tot;//编号
    
        void init(){//初始化0号点
            tot=1;
            val[0]=fail[0]=last[0]=0;
            memset(tire[0],0,sizeof(tire[0]));
        }
    
        void insert(char *s,int v){//构造trie与val数组，v需非0，表示一个单词节点
            int len=strlen(s);
            int root=0;
            for(int i=0;i<len;i++){
                int id=s[i];
                if(tire[root][id]==0){
                    tire[root][id]=tot;
                    memset(tire[tot],0,sizeof(tire[tot]));
                    val[tot++]=0;
                }
                root=tire[root][id];
            }
            val[root]=v;
        }
    
        void build(){//构造fail与last
            queue<int> q;
            last[0]=fail[0]=0;
            for(int i=0;i<128;i++){
                int root=tire[0][i];
                if(root!=0){
                    fail[root]=0;
                    last[root]=0;
                    q.push(root);
                }
            }
    
            while(!q.empty()){//bfs求fail
                int k=q.front();
                q.pop();
                for(int i=0;i<128;i++){
                    int u=tire[k][i];
                    if(u==0)
                        continue;
                    q.push(u);
    
                    int v=fail[k];
                    while(v && tire[v][i]==0)
                        v=fail[v];
                    fail[u]=tire[v][i];
                    last[u]=val[fail[u]]?fail[u]:last[fail[u]];
                }
            }
        }
    
        void print(int i){//递归打印与结点i后缀相同的前缀节点编号
            if(val[i]){
                res[val[i]]++;
                print(last[i]);
            }
        }
    
        void query(char *s){//匹配
            int len=strlen(s);
            int j=0;
            for(int i=0;i<len;i++){
                int id=s[i];
                while(j && tire[j][id]==0)
                    j=fail[j];
                j=tire[j][id];
                if(val[j])
                    print(j);
                else if(last[j])
                    print(last[j]);
            }
        }
    }ac;
    char P[1000][1000];
    char T[2000000+10];
    int main(){
        int n;
        while(scanf("%d",&n)!=EOF&&n){
            memset(res,0,sizeof(res));
            ac.init();
    
            for(int i=1;i<=n;i++){
                scanf("%s",P[i]);
                ac.insert(P[i],i);
            }
            ac.build();
    
            scanf("%s",T);
            ac.query(T);
            for(int i=1;i<=n;i++)
                if(res[i])
                    printf("%s: %d\n",P[i],res[i]);
        }
        return 0;
    }