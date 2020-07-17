// 呜呜呜syfnb
#include <bits/stdc++.h>
using namespace std;
#define maxn 200001
#define ll long long
ll goal[maxn],num[maxn],label[maxn][3],id=0;//goal[i]，第i个人的目标，num[i],第i个人有几个摄像头，label[i][j]第i个人的第j个摄像头是装在哪儿的
ll done[maxn]; //done[i]是第i个观测站已经完成了啥任务
vector <int> vec2[maxn]; //这边为了优化时间，不然的话type2录一次得跑maxn，vec遍历一下就完事了。
ll ans[maxn];
bool bo[maxn];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);//输入n个观测站,m个events
    int last=0,size_of_ans=0;
    for (int i=1;i<=m;i++){
        int TYPE;
        scanf("%d",&TYPE);
        if (TYPE==1){
            id++;
            scanf("%d%d",&goal[id],&num[id]); //goal的目标，多少
            goal[id]^=last;
            for (int i=0;i<num[id];i++) //label[id][i]->id,第几个是啥观测站
            //那么这时候观测站vec[label[id][i]]加一个id
            {
                int tmp;
                scanf("%d",&tmp);
                tmp^=last;//grd，竟然还加密
                label[id][i]=tmp;
                vec2[label[id][i]].push_back(id);
            }
        }
        if (TYPE==2){
            size_of_ans=0;
            int x,y;//x-th y min
            scanf("%d%d",&x,&y);
            x^=last,y^=last;
            int len=vec2[x].size();
            for (int i=0;i<len;i++){
                done[vec2[x][i]]+=y;
                if (done[vec2[x][i]]>=goal[vec2[x][i]] && !bo[vec2[x][i]]) ans[++size_of_ans]=vec2[x][i],bo[vec2[x][i]]=1;
            }
            if (size_of_ans>=1) sort(ans+1,ans+size_of_ans);//不加if竟然炸呜呜
            cout<<size_of_ans;
            for (int i=1;i<=size_of_ans;i++) cout<<" "<<ans[i];
            cout<<endl;
            last=size_of_ans;
        }
    }
}