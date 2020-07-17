//JSOI 2007
/* a[i]!=0 时应该是a[i+1]%3 和 a[i+2] %3 都相等 忘记%3
    不会传入数组
    判断条件再次失误，顺序失误，外层判断对子是哪个，内层判断少哪个补上，先补上再计算。（而且是>=2就可以了）*/
//O2优化后AC
//上面全错，判断是否为顺子，如果有刻子就把刻子全删掉，剩下的组成顺子，直接删，删完就查，如果下面一个负的就判错
#include <bits/stdc++.h>
using namespace std;
int n,m,tax[401];
int ans[401];

int checker()
{
    int a[401];
    for (int i=1;i<=n;i++) a[i]=tax[i];
    for (int i=1;i<=n-2;i++)
    {
        if (a[i]>0)
        {
            if (a[i]<=a[i+1] && a[i]<=a[i+2])
            {
                a[i+1]-=a[i]; a[i+2]-=a[i]; 
                a[i]=0; 
            }
        }
    }
    for (int i=1;i<=n;i++) if (a[i]%3) return 0;
    return 1;
}

int main()
{
    cin>>n>>m;
    int x;
    for (int i=1;i<=3*m+1;i++)
    {
        cin>>x; tax[x]++;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            tax[j]++;
          /* if (i==7 && j==7) 
                cout<<"here"<<endl;*/
            if (tax[i]>=2) tax[i]-=2; else {tax[j]--; continue;}
            if (checker()) ans[j]++;
            tax[j]--;
            tax[i]+=2;
        }
    for (int i=1;i<=n;i++)
        if (ans[i]!=0) cout<<i<<" "; 
        
        return 0;
}