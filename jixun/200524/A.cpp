#include <bits/stdc++.h>
using namespace std;
#define maxn 300005
#define ll long long
ll point[maxn],totrank[maxn];
unordered_set <int> chafen[maxn];
int main(){
    int n,w;
    ios::sync_with_stdio(false); cin.tie(0);
    int maxpoint=0;
    for (int i=1;i<=w;i++){
        int k;
        cin>>k;
        for (int j=1;j<=k;j++){
            int tmp;
            cin>>tmp;
            chafen[point[tmp]].erase(tmp);
            chafen[point[tmp]+1].insert(tmp);
            if (maxpoint>point[tmp]) maxpoint=point[tmp];
        }
        int rank=0;
        for (int j=maxpoint;j>=0;j--){
            rank+=chafen[j].count();
            for (auto i:chafen[j]){
                rank[i]+=ans+1;
            }
        }
    }
}