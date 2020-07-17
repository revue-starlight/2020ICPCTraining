#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while (cin>>s){
        int len=s.length();
        int a[301];
        memset(a,0,sizeof(a));
        int tot=1;
        for (int i=len-1;i>=2;i--){
            int t=0;
            int yushu=0;
            a[0]=a[0]+(s[i]-'0');
            while (t<tot || yushu!=0){
                yushu=yushu*10+a[t];
                a[t]=yushu/8;
                yushu%=8;
                t++;
            }
            tot=t;
        }
        cout<<s<<"[8]="<<a[0]<<".";
        for (int i=1;i<tot;i++) cout<<a[i];
        cout<<"[10]"<<endl;
    }
}