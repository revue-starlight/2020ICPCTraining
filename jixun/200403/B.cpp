#include <bits/stdc++.h>
#define maxn 100004
using namespace std;

struct answer {
    int L, P;
};

answer ans[maxn];


struct place {
    int sp, k;
};
struct node {
    int next[26], cnt;
    vector <place> v;
    int point;
}tree[maxn];
int tot = 0;

void build(char* s, int sp, int k) {
    int len = strlen(s); int now = 0;
    for (int i = 0; i < len; i++) {
        int ch = s[i] - 'a';
        if (tree[now].next[ch]== 0)
            tree[now].next[ch] = ++tot;
        now = tree[now].next[ch];
    }
    tree[now].cnt++;
    place tmp; tmp.k = k+1; tmp.sp = sp;
    tree[now].v.push_back(tmp);
    tree[now].point = 0;
}

bool check(char* s, int num) {
    int len = strlen(s);
    int now = 0;
    for (int i = 0; i < len; i++) {
        int ch = s[i] - 'a';
        if (tree[now].next[ch] == 0) return false;
        now = tree[now].next[ch];
    }
    if (tree[now].cnt == 0) return false;
    int veclen = tree[now].cnt;
    int point = tree[now].point;
    ans[num].L = tree[now].v[point].sp;
    ans[num].P = tree[now].v[point].k;
    tree[now].point = (tree[now].point + 1) % veclen;
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        char str[100];
        for (int j = 0; j < t; j++) {
            scanf("%s", str);
            getchar();
            build(str, i, j);
        }
    }
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        char str[100];
        scanf("%s", str);
        getchar();
        if (!check(str, i)) {
            printf("NOT POSSIBLE");
            return 0;
        }
    }

    for (int i = 0; i < t; i++) printf("%d %d\n", ans[i].L, ans[i].P);
    return 0;
}