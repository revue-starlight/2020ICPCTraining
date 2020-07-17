#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
int a[maxn];
int cnt[maxn];
bool bo[maxn];
stack <int> s;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
    s.push(a[1]); bo[a[1]]=1; cnt[a[1]]--;
    for (int i=2;i<=n;i++){
        cnt[a[i]]--;
        if (bo[a[i]]) continue;
        while (s.size() && cnt[s.top()] && a[i]<s.top()){
            bo[s.top()]=0; s.pop();
        }
        bo[a[i]]=1; s.push(a[i]);
    }
    vector <int> ans;
    for (int i=1;i<=k;i++) ans.push_back(s.top()),s.pop();
    for (int i=k-1;i>=0;i--) cout<<ans[i]<<" ";
}