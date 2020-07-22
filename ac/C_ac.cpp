#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <queue>
using ULL       = unsigned long long;
const ULL MAX_N = 5000007;
const ULL MAX_M = 26;
const ULL INF   = 0x3fffffff;

inline ULL ctoi(char &c)
{
    return c - 'a';
}

struct Trie
{
    struct Node
    {
        ULL next[MAX_M];
        ULL fail;
        ULL count;
    } nodes[MAX_N];
    ULL root, cnt;

    void clear(void)
    {
        cnt  = 0;
        root = newNode();
    }

    ULL newNode()
    {
        Node &cur = nodes[cnt];
        for(ULL i = 0; i < MAX_M; i++)
        {
            cur.next[i] = INF;
        }
        cur.fail  = INF;
        cur.count = 0;
        ++cnt;
        return cnt - 1;
    }

    void insert(char buf[])
    {
        auto len = strlen(buf);
        ULL  cur = root;
        for(size_t i = 0; i < len; i++)
        {
            ULL &next = nodes[cur].next[ctoi(buf[i])];
            if(next == INF)
            {
                next = newNode();
            }
            cur = next;
        }
        nodes[cur].count++;
    }

    void buildFailTree(void)
    {
        std::queue<ULL> que;
        nodes[root].fail = root;
        for(ULL i = 0; i < MAX_M; ++i)
        {
            auto cur = nodes[root].next[i];
            if(cur != INF)
            {
                nodes[cur].fail = root;
                que.push(cur);
            }
            else
            {
                nodes[root].next[i] = root;
            }
        }
        while(!que.empty())
        {
            auto cur = que.front();
            que.pop();
            for(ULL i = 0; i < MAX_M; ++i)
            {
                ULL next = nodes[cur].next[i];
                if(next==INF)
                {
                    nodes[cur].next[i] = nodes[nodes[cur].fail].next[i];
                }
                else
                {
                    nodes[next].fail = nodes[nodes[cur].fail].next[i];
                    // std::cerr << next << "\n";
                    que.push(next);
                }
            }
        }
    }
    int query(char buf[])
    {
        ULL len = strlen(buf);
        ULL cur = root;
        ULL ans = 0;
        for(ULL i = 0; i < len; i++)
        {
            cur     = nodes[cur].next[ctoi(buf[i])];
            ULL tmp = cur;
            while(tmp != root&&nodes[tmp].count!=INF)
            {
                ans += nodes[tmp].count;
                nodes[tmp].count = INF;
                tmp = nodes[tmp].fail;
            }
        }
        return ans;
    }
    void debug(void)
    {
        for(ULL i = 0; i < cnt; i++)
        {
            printf("{\"id\" : %3llu , \"fail\" : %3llu , \"chi\" : [", i, nodes[i].fail);
            for(ULL j = 0; j < MAX_M; j++)
            {
                printf(" %3llu ,", nodes[i].next[j]);
            }
            printf("],\n");
        }
    }
};

char buf[MAX_N];
Trie acm;
int  main(void)
{
    int n = 1;
    // scanf("%d", &n);
    while(n--)
    {
        int m;
        scanf("%d", &m);
        acm.clear();
        while(m--)
        {
            scanf("%s", buf);
            acm.insert(buf);
        }
        acm.buildFailTree();
        scanf("%s", buf);
        printf("%d\n", acm.query(buf));
        // acm.debug();
    }
    return 0;
}