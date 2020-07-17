#include <iostream>
int a[11];
int ans[100000][11];
using namespace std;
int t=0;
void work(int k,int l)
{
    if (k==11 && l==0) {t++; for (int i=1;i<=10;i++) ans[t][i]=a[i]; return;}
    if (k>10) return;
    a[k]=1; work(k+1,l-1);
    a[k]=2; work(k+1,l-2);
    a[k]=3; work(k+1,l-3);
}

int main()
{
    int n;
    cin>>n;
    if (n<10|| n>30) {cout<<0; return 0;}
    work(1,n);
    cout<<t<<endl;
    for (int i=1;i<=t;i++)
    {
        for (int j=1;j<=10;j++)
        cout<<ans[i][j]<<" ";
    cout<<endl;
    }
    return 0;
}