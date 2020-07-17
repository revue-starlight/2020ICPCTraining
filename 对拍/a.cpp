#include <bits/stdc++.h>
using namespace std;
struct node{
    long long l,r,d;
}s[200002];
long long a[200002];

bool cmp(node a,node b)
{
    return a.d>b.d;
}
int main()
{
    ios::sync_with_stdio(false);    cin.tie(0);
    long long m,n,k,t;
    cin>>m>>n>>k>>t;
    for (long long i=1;i<=m;i++)
    cin>>a[i]; //read a[i]
        sort(a+1,a+1+m); //sort
    for (long long i=1;i<=k;i++)
    {
        cin>>s[i].l>>s[i].r>>s[i].d;
    } //read traps data
    sort(s+1,s+1+k,cmp); //从大到小排序
    t-=(n+1); //从左往右带领军队至少要一个n+1
    long long trap=1,soilder=m;
    while (1)//O（n)的一个循环
    {
        while (a[soilder]>=s[trap].d && soilder>=1) soilder--; //可以越过雷池的士兵先出列，指针指向第一个无法越过雷池的士兵的下标
        if (soilder==0) {cout<<m<<endl; return 0;} //雷池太水。输出m结束
        while (s[trap].d>=a[soilder]) //遇到某个士兵太水，去拆雷。（拆掉的雷一定是当前雷池里最萌的雷）
        {
            //要拆trap救命
            if (s[trap].r>s[trap].l)
            {t-=(s[trap].r-s[trap].l)*2; //往返一次时 间*2
            trap++;
            if (t<0) {cout<<m-soilder<<endl; return 0;} //没时间的话那就不带你去了。
            } //由于弹和数组都是有威力的，而初始化时雷为0，所以万一弹被拆完了，就直接d=0，然后soilder一直清空到结尾。但是就得多开一个以免越界
            else trap++; 
        }
    }

          
}