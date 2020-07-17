#include <bits/stdc++.h>
using namespace std;
int main(){
    int s[3007],b[4];
    int n;
    while (cin>>n){
        memset(s,0,sizeof(s));
        s[0]=1;
        int tot=1;
        for (int i=1;i<=n;i++){
            int u=i,sw=0;
            int c[3005];
            
            memset(c,0,sizeof(c));
            while (u!=0){
                int k=u%10;
                u/=10;
                for (int i=0;i<tot;i++){
                     c[i+sw]+=s[i]*k;
                }
                for (int i=0;i<tot;i++){
                    c[i+sw+1]+=c[i+sw]/10;
                    c[i+sw]=c[i+sw]%10;
                }
                sw++;
                for (int i=3000;i>0;i--) if (c[i]!=0) {if (tot<i+1) tot=i+1; break;}
            }
            for (int i=0;i<tot;i++) s[i]=c[i];
        }
        for (int i=tot-1;i>=0;i--) cout<<s[i];
        cout<<endl;
    }
}