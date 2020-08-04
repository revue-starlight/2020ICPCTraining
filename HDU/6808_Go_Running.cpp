/*
bfs具体步骤：
设二分图为X和Y两部分

把X中所有没匹配的点加入队列
每次出来一个点u，对于它连的Y中的每个点v，如果v没访问过且没匹配过，找到增广路，否则把v的匹配点压入队列
bfs的时候顺便记录一下每个点在bfs中的层次，看代码比较容易理解
*/
bool bfs(){
    memset(dep,0,sizeof(dep));
    queue <int> q;
    while (!q.empty()) q.pop();
    for (int i=1;i<=n;i++) if (con[i]==-1) q.push(i);
    bool flag=false;
    while (!q.empty()){
        int u=q.front(); q.pop();
        for (int i=head[u]; i!=-1; i=e[i].next){
            int v=e[i].v;
            if (!dep[v]){
                dep[v]=dep[u]+1;
                if (con[v]==-1) flag=true;
                else dep[con[v]]=dep[v]+1;
            }
        }
    }
}