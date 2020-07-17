#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=3e5+10;
int a[maxn];
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        bool bo=true;
        for (int i=1;i<=n;i++) cin>>a[i];
        a[n+1]=0;
        
        int temp=a[1];
        int k=2;
        int tmp=0;
        while (temp<a[k]){
            temp=min(a[k],temp);
            k++;
        }
        while (k<=n){
            int maxx=INT_MAX;
            tmp=a[k];
            while (tmp<=a[k]) {if (k>n) break; if (a[k]>temp && a[k]<maxx) maxx=a[k]; k++;}
            if (maxx==INT_MAX) {bo=false; cout<<"NO"<<endl; break;}
            temp=maxx;
        }
        if (bo) {cout<<"YES"<<endl;}
    }
}