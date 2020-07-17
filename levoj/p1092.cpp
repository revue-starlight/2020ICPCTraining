#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct matrix{
    ll arr[15][15];
};
ll n;
inline matrix rotation(matrix a){
    matrix b;
    memset(b.arr,0,sizeof(b.arr));
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++){
            b.arr[j][n-i+1]=a.arr[i][j];
        }
    return b;
}
inline matrix add(matrix a,matrix b){
    matrix ans;
    memset(ans.arr,0,sizeof(ans.arr));
    for (ll i=1;i<=n;i++)
     for (ll j=1;j<=n;j++){
         ans.arr[i][j]=a.arr[i][j]+b.arr[i][j];
     }
     return ans;
}

inline matrix mul(matrix a,ll k){
    matrix ans;
    memset(ans.arr,0,sizeof(ans.arr));
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++)
        ans.arr[i][j]=k*a.arr[i][j];
    return ans;
}

int main(){
    ll k;
    while (cin>>n){

    matrix x;
    memset(x.arr,0,sizeof(x.arr));
    for (ll i=1;i<=n;i++)
     for (ll j=1;j<=n;j++){
        cin>>x.arr[i][j];
    }
    cin>>k;
    matrix times_x;
    memset(times_x.arr,0,sizeof(times_x.arr));
    times_x=add(x,times_x);
    times_x=add(rotation(x),times_x);
    times_x=add(rotation(rotation(x)),times_x);
    times_x=add(rotation(rotation(rotation(x))),times_x);
    matrix ans;
    memset(ans.arr,0,sizeof(ans.arr));
    if (k>=4){
        ll q=k/4;
        ans=mul(times_x,q);   
    }
    matrix tmp;
    memset(tmp.arr,0,sizeof(tmp.arr));
    if (k%4==0) {
        tmp=add(x,tmp);
    }
    if (k%4==1){
        tmp=add(x,tmp);
        tmp=add(rotation(x),tmp);
    }
    if (k%4==2){
        tmp=add(x,tmp);
        tmp=add(rotation(x),tmp);
        tmp=add(rotation(rotation(x)),tmp);
    }
    ans=add(tmp,ans);
    for (ll i=1;i<=n;i++){
        for (ll j=1;j<n;j++) cout<<ans.arr[i][j]<<" ";
        cout<<ans.arr[i][n]<<endl;
    }
    }
}