#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace  std;
typedef unsigned long long ull;
const int MAXN = 5e6 + 10;
const int H = 27;
ull has[MAXN], power[MAXN];
char s[MAXN], t[MAXN];
int cnt[MAXN][30];

ull getHash(int l, int r) {
    return has[r] - has[l - 1] * power[r - l + 1];
}

bool test(int len, int n) {
    set<ull> st;
    copy(s + 1, s + 1 + len, t + 1);
    copy(s + 1, s + 1 + len, t + len + 1);
    st.insert(has[len]);
    for (int i = 1; i < len; ++i) {
        ull tmp = getHash(i + 1, len);
        tmp = tmp * power[i] + has[i];
        st.insert(tmp);
    }

    // for (auto x: st) {
    //     cout << x << '\n';
    // }
    // exit(0);

    for (int i = len; i <= n; i += len) {
        if (!st.count(getHash(i - len + 1, i))) {
            return false;
        }
    }
    return true;
}

bool good(int p) {
    for (int i = 0; i < 26; ++i) {
        if (cnt[p / 2][i] * 2 != cnt[p][i]) {
            return false;
        }
    }
    return true;
}

int main() {
    power[0] = 1;
    for (int i = 1; i < MAXN; ++i) power[i] = power[i - 1] * H;
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cin >> (s + 1);
        for (int i = 0; i < 27; ++i) {
            for (int j = 0; j <= n; ++j) {
                cnt[j][i] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                cnt[i][j] = cnt[i - 1][j];
            }
            ++cnt[i][s[i] - 'a'];
        }
        for (int i = 1; i <= n; ++i) {
            has[i] = has[i - 1] * H + s[i] - 'a' + 1;
        }

        unsigned num = 0;
        bool suc = 0;
        for (int i = 1; i <= n; ++i) {
            num ^= (1u << (s[i] - 'a'));
            if (num == 0 && (i % 2 == 0) && n % (i / 2) == 0 && good(i) && test(i, n)) {
                suc = 1;
                cout << "YES\n";
                break;
            }
        }
        if (!suc) {
            cout << "NO\n";
        }
    }
    return 0;
}
