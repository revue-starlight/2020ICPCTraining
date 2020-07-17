#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    while (cin>>s1>>s2){
         int a[105],b[105],c[206];
         memset(a,0,sizeof(a));
         memset(b,0,sizeof(b));
         memset(c,0,sizeof(c));
        int l1=s1.length(),l2=s2.length();
        for (int i=0;i<l1;i++) a[l1-i-1]=s1[i]-'0';
        for (int i=0;i<l2;i++) b[l2-i-1]=s2[i]-'0';
        int l;
        if (l1<l2) l=l2; else l=l1;
        for (int i=0;i<l1;i++){
            for (int j=0;j<l2;j++){
                c[j+i]=c[j+i]+a[i]*b[j];
            }
            for (int j=0;j<l2+i;j++){
                c[j+1]=c[j]/10+c[j+1];
                c[j]=c[j]%10;
            }
        }
        int tot=l1+l2; 
        if (c[tot-1]>0) tot++;
        for (int i=tot-2;i>=0;i--) cout<<c[i];
        cout<<endl;
    }
}