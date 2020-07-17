#include <bits/stdc++.h>
using namespace std;

bool work(int x){
    while (x!=0){
        if (x%2==1) return false;
        x/=2;
    }    
    return true;
}
int main()
{
    int a[20];
    int sum=2,ans=0;
    while (sum<=1000)
    {
        a[++ans]=sum+1;
        sum*=2;
    }
    for (int i=1;i<=ans;i++) cout<<a[i]<<" ";
    int n;
    while (cin>>n){
        int p=0;
        bool bo=false;
        while (a[p]<=n){
            if (work(n-a[p])){
                cout<<"Kiki"<<endl;
                bo=true;
                break;
            }
            p++;
        }
        if (!bo) cout<<"Cici"<<endl;
    }
    return 0;   
}