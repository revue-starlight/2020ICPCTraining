/*#include <bits/stdc++.h>
using namespace std;
long long cnt=1;
struct node
{
    long long u,w, v, next;
    bool operator<(const node& b) const
    {
        return w > b.w;
    }
} edge[400005];
long long head[10003], n, a, b, c, m;
long long dis[10003];
long long bcj[10003];
long long sum;
//链式前向星给了。
//head[i] 第i个节点里的起始边
priority_queue<node> q;
void add(long long u, long long v, long long w)
{
    edge[cnt].u=u;
    edge[cnt].w=w;
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt;
    cnt++;
}

void samefather(long long x,long long y)
{
    if (bcj[x]!=bcj[y]) bcj[y]=bcj[x];
}

int main()
{
    cin>>n>>m;
   
    for (long long i=1;i<=n;i++)
        bcj[i]=i;
    for (long long i = 2; i <= n; i++)
        dis[i] = LONG_LONG_MAX;
    for (long long i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        add(a, b, c);
        add(b,a,c);
    }
    
    long long ans=1,x=1; //初始化单源
    while (ans<n)
    {
        for (long long i=head[x];i;i=edge[i].next)
        {
            q.push(edge[i]);//压入所有的边
        }
       
        node tmp;

        do{
        tmp=q.top(); //如果有不同边的话弹出
        q.pop();} while (bcj[tmp.v]==bcj[tmp.u]);

        samefather(x,tmp.v);
        dis[tmp.v]=dis[tmp.u]+tmp.w;
        ans++;
        sum+=tmp.w;
        x=tmp.v;
    }
    cout<<sum<<endl;
    return 0;
    
}*/ 

#include<bits/stdc++.h>
using namespace std;
#define re register
#define il inline
il int read()
{
    re int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}//快读，不理解的同学用cin代替即可
#define inf 123456789
#define maxn 5005
#define maxm 200005
struct edge
{
    int v,w,next;
}e[maxm<<1];
//注意是无向图，开两倍数组
int head[maxn],dis[maxn],cnt,n,m,tot,now=1,ans;
//已经加入最小生成树的的点到没有加入的点的最短距离，比如说1和2号节点已经加入了最小生成树，那么dis[3]就等于min(1->3,2->3)
bool vis[maxn];
//链式前向星加边
il void add(int u,int v,int w)
{
    e[++cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
//读入数据
il void init()
{
    n=read(),m=read();
    for(re int i=1,u,v,w;i<=m;++i)
    {
        u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
    }
}
il int prim()
{
    //先把dis数组附为极大值
    for(re int i=2;i<=n;++i)
    {
        dis[i]=inf;
    }
    //这里要注意重边，所以要用到min
    for(re int i=head[1];i;i=e[i].next)
    {
        dis[e[i].v]=min(dis[e[i].v],e[i].w);
    }
    while(++tot<n)//最小生成树边数等于点数-1
    {
        re int minn=inf;//把minn置为极大值
        vis[now]=1;//标记点已经走过
        //枚举每一个没有使用的点
        //找出最小值作为新边
        //注意这里不是枚举now点的所有连边，而是1~n
        for(re int i=1;i<=n;++i)
        {
            if(!vis[i]&&minn>dis[i])
            {
                minn=dis[i];
                now=i;
            }
        }
        ans+=minn;
        //枚举now的所有连边，更新dis数组
        for(re int i=head[now];i;i=e[i].next)
        {
            re int v=e[i].v;
            if(dis[v]>e[i].w&&!vis[v])
            {
                dis[v]=e[i].w;
            }
        }
    }
    return ans;
}
int main()
{
    init();
    printf("%d",prim());
    return 0;
}

/*SPFA
bool SPFA(int s,int n)
{
	queue <int> q;
	memset(vis,inf,sizeof(vis));
	memset(ven,0,sizeof(ven));
	memset(nums,0,sizeof(nums));
	vis[s]=0;//初始化距离 
	ven[s]=1,nums[s]++;//标记s节点在队列，队列次数+1 
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();//出队 
		ven[x]=0;//标记不在队列 
		for(int i=pre[x]; ~i; i=a[i].next)//遍历与x节点连通的点 
		{
			int y=a[i].y;
			if(vis[y]>vis[x]+a[i].time)//更新 
			{
				vis[y]=vis[x]+a[i].time;
				if(!ven[y])
				//由于更新了节点，所以后续以这个为基础的最短路，也要更新下
				//所以如果在队列就不用加入，不在的话加入更新后续节点 
				{
					q.push(y);
					ven[y]=1;//标记这个节点在队列中 
					nums[y]++;//记录加入次数 
					if(nums[y]>n)//如果这个点加入超过n次，说明存在负圈，直接返回 
						return false;
				}
			}
		}
	}
	return true;
}
*/