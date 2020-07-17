
#include <bits/stdc++.h>
using namespace std;
#define maxn 150005
#define ll long long
ll xxxx,val[maxn],n;
int ans[maxn];
struct node{
    ll id,val,level;
    bool operator < (const node &a) const{
        if (level==a.level) return val<a.val;
        else
        return level>a.level;
    }
};

int main(){
    scanf("%lld",&xxxx);
    for (int CASE=1;CASE<=xxxx;CASE++){
        priority_queue <node> pq;
        scanf("%lld",&n);
        getchar();
        string s;
        getline(cin,s);
        for (int i=0;i<n;i++){
            val[i]=s[i]-48;
            node tmp; tmp.id=i; tmp.val=val[i]; tmp.level=1; pq.push(tmp);
        }
        int maxx=0,now_level=1;
        while (pq.size()){
            node tmp=pq.top(); pq.pop();
            if (tmp.level==n+1) break;
            if (now_level==tmp.level){
                if (maxx<tmp.val) maxx==tmp.val,ans[tmp.level]=tmp.val;
                else if (maxx>tmp.val) continue;
            }
            if (now_level<tmp.level) {now_level++; maxx=0;}
            ll id_next=(tmp.id*tmp.id+1)%n;
            node tmp2;
            tmp2.id=id_next; tmp2.level=tmp.level+1; tmp2.val=val[id_next];
            pq.push(tmp2);
        }
        printf("Case #%d :",CASE);
        for (int i=1;i<=n;i++) printf("%d",ans[i]);
        printf("\n");
    }
}