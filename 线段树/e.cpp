#include <bits/stdc++.h>
using namespace std;
const int maxn=200001;
//int mp[maxn][maxn];
//int cnt[maxn];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<int> > mp(n, vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&mp[i][j]);
            mp[i][j]--;
        }
    }
    long long ans=0;
    for(int j=0;j<m;j++)
    {
        vector<int> cnt(n);
        //memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            if(mp[i][j] % m == j)
            {
                int pos = mp[i][j] / m;
                if(pos<n)
                {
                    cnt[(i-pos+n)%n]++;
                }
            }
        }
        int cur = n-cnt[0];
        for(int i=1; i<n; i++)
        {
            cur = min(cur, n - cnt[i] + i);
        }
        ans+=cur;
    }
    printf("%lld\n",ans);
    //cout << "Hello world!" << endl;
    return 0;
}