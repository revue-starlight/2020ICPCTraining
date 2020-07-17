#include <bits/stdc++.h>
using namespace std;
#define maxn 11
double p[maxn]; 
int num[maxn];
double dead[maxn][101];

int main(){
    int t;
    scanf("%d",&t);
    for (int kase=1;kase<=t;kase++){
        int n;
        cin>>n;
        for (int i=1;i<=n;i++){
            scanf("%d%lf",&num[i],&p[i]);
        }
        //1：
        //假设我们走到了k步，发现k步全死了的概率；
        for (int k=1;k<=40;k++){
            for (int j=1;j<=n;j++){//任意一个在k步死掉的概率为(1-p^k)，而同时死掉的概率给一个n次方
                dead[k][j]=pow((1-pow(p[j],k)),n);
            }
        }
        //2.倘若某一种是活下来的那个，也就是说在这一步他没死，但是其他的全都死了。
        //累加所有步数
        for (int i=1;i<=n;i++){//对每种种类搞一下
            double ans=0;
            for (int k=1;k<=40;k++){//他这一步赢的概率
            double p_qitadequansile=1;
                for (int p=1;p<=n;p++){
                    if (p==i) continue;
                    p_qitadequansile*=dead[k][p];
                }
                double benlunhuoxia=p_qitadequansile*(1-dead[k][i]);
                ans+=benlunhuoxia;
            }
            printf("%.6lf ",ans);
        }
        printf("\n");
    }
}