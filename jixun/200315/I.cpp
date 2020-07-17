// 别wa了
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define maxn 200001
#define ll long long
ll goal[maxn],num[maxn],label[maxn][3],id=0;//goal[i]，第i个人的目标，num[i],第i个人有几个摄像头，label[i][j]第i个人的第j个摄像头是装在哪儿的
ll done[maxn]; //done[i]是第i个观测站已经完成了啥任务
set <int> vec2[maxn]; //这边为了优化时间，不然的话type2录一次得跑maxn，vec遍历一下就完事了。
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
            scanf("%d%d",&goal[id],&num[id]); //goal的目标，以及这个人占了多少个观测站
            goal[id]^=last; //巨傻逼的加密
            for (int i=0;i<num[id];i++) //label[id][i]，这是一个表，id个人的第i个观测站是哪个观测站
            //那么这时候观测站vec[label[id][i]]加一个id
            {
                int tmp;
                scanf("%d",&label[id][i]);
                label[id][i]^=last;
                vec2[label[id][i]].insert(id);//这里面push_back(id)，这个观测站里有id的照相机
            }
        }
        if (TYPE==2){
            size_of_ans=0;
            int x,y;//x-th y min
            scanf("%d%d",&x,&y);
            x^=last,y^=last;
            int len=vec2[x].size();
            for (auto int i:vec2[x]){
                if (bo[i]) vec2.erase(i);
                done[i]+=y;
                if (done[i]>=goal[i]) ans[++size_of_ans]=i,bo[i]=1;
            }
            printf("%d",size_of_ans);   
            for (int i=1;i<=size_of_ans;i++) printf(" %d",ans[i]);
            printf("\n");
            last=size_of_ans;
        }
    }
}