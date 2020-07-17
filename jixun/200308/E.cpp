#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
const int maxn = 510;
bool vis[maxn][maxn][2]; // 0表示is关系，1表示has关系
int is[maxn][maxn];
int has[maxn][maxn];
map <string, int> mp;
int tot = 0;

int strint(string s) // 字符串转化为数字标号
{
    if (mp.count(s))
        return mp[s];
    mp[s] = tot++;
}

void bfs(int u)
{
    queue <pii> Q;
    vis[u][u][0] = 1;
    Q.push(pii(u, 0)); // 节点与is/has关系
    while (!Q.empty())
    {
        pii v = Q.front();
        Q.pop();
        for (int i = 0; i < tot; ++i)
        {
            if (!vis[u][i][v.ss] && is[v.ff][i]) // is-is -> is
            {
                vis[u][i][v.ss] = 1;
                Q.push(pii(i, v.ss));
            }
            if (!vis[u][i][1] && has[v.ff][i]) // is-has -> has / has-is -> has / has-has -> has
            {
                vis[u][i][1] = 1;
                Q.push(pii(i, 1));
            }
        }
    }
}

int main()
{
    int n, m;
    string a, b, c;
    scanf("%d%d", &n, &m);
    mp.clear();
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        strint(a), strint(c);
        if (b[0] == 'i') // is关系建边
            is[strint(a)][strint(c)] = 1;
        else if (b[0] == 'h') // has关系建边
            has[strint(a)][strint(c)] = 1;
    }
    for (int i = 0; i < tot; ++i) // 对每个节点进行搜索改变相应关系
        bfs(i);
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        if (b[0] == 'i')
        {
            if (vis[strint(a)][strint(c)][0])
                printf("Query %d: true\n", i);
            else
                printf("Query %d: false\n", i);
        }
        else
        {
            if (vis[strint(a)][strint(c)][1])
                printf("Query %d: true\n", i);
            else
                printf("Query %d: false\n", i);
        }
    }
    return 0;
}