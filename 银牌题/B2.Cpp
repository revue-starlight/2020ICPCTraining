/*明明是概率统计*/
/*考虑到无限情况，走了一定步数之后可能分布于任何一个点，
所以初始点没有用*/
#pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>
using namespace std;
const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};
int t;
map <pair<int,int>,int> mp;  
int check(int x,int y,int n){
    if (x<0 || x>=n || y<0 || y>=n) return false;
    return true;
}
int main(){
    scanf("%d",&t);
    for (int kase=1;kase<=t;kase++){
        mp.clear();
        int n,k;
        scanf("%d%d",&n,&k);
        int sum((3*4)+((n-2)*4*4)+(n-2)*(n-2)*5),sumr=((3*3)+((n-2)*2*4)+((n-2)*(n-1)/2*5));
        for (int i=1;i<=k;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            mp[{x,y}]=6;
            for (int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];
                mp[{xx,yy}]++;
            }
        }
            for (auto it:mp){
                int xx=it.first.first,yy=it.first.second;
                if (check(xx,yy,n)){
                    int res=5;
                    if (xx==0 && yy==0 || xx==0 && yy==n-1 || xx==n-1 && yy==0 || xx==n-1 && yy==n-1)
                        res=3;
                    else if (xx==0 || xx==n-1 || yy==0 || yy==n-1) res=4;
                    if (xx+yy>=n-1) sumr=sumr-min(res,it.second);
                    sum=sum-min(res,it.second);
                }
            }
        int tmp=__gcd(sum,sumr);
        printf("Case #%d: %d/%d\n",kase,sumr/tmp,sum/tmp);
        
    }
}