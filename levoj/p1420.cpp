#include <bits/stdc++.h>
using namespace std;
struct node{
    int arr[1000];
};
node ans[200];
inline node add(const node &a,const node &b){
    node c;
    memset(c.arr,0,sizeof(c.arr));
    for (int i=1;i<1000;i++)
    {
        c.arr[i]=c.arr[i]+a.arr[i]+b.arr[i];
        c.arr[i+1]+=c.arr[i]/10;
        c.arr[i]%=10;
    }
    return c;
}

inline node mul(const node &a,const node &b){
    node c;
    memset(c.arr,0,sizeof(c.arr));
    for (int i=1;i<1000;i++){
        c.arr[i]=c.arr[i]+a.arr[i]*b.arr[i];
        c.arr[i+1]+=c.arr[i]/10;
        c.arr[i]%=10;
    }
}

int main(){
    int n,m;
    while (cin>>n>>m){
        for (int i=0;i<200;i++) memset(ans[i].arr,0,sizeof(ans[i].arr));
        ans[1].arr[1]=1;
        for (int i=2;i<=n;i++){    
            for (int j=i;j>=2;j++){
            node tmp;
            memset(tmp.arr,0,sizeof(tmp.arr));
            int temp=m;
            int cnt=1;
            while (temp){
                tmp.arr[cnt]=temp%10; temp/=10;
            }
            ans[j]=add(mul(tmp,ans[j]),ans[j-1]);
            }
        }
        if (m>n) cout<<0<<endl;
        else {
            int k=999;
            while (ans[m].arr[k]==0) k--;
            for (int i=k;i>=1;i--) cout<<ans[m].arr[i];
        }
    }
}