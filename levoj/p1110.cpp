#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[2001],b[2001],c[2002];
    string s1,s2;
    while (cin>>s1>>s2){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int len1=s1.length(),len2=s2.length();
    for (int i=0;i<len1;i++) a[len1-1-i]=s1[i]-'0';
    for (int i=0;i<len2;i++) b[len2-1-i]=s2[i]-'0';
    int len;
    if (len1>len2) len=len1; else len=len2;
    for (int i=0;i<len;i++){
        c[i]=a[i]+b[i]+c[i];
        c[i+1]+=(c[i]/10);
        c[i]%=10;
    }
    if (c[len]>0) len++;
    for (int i=len-1;i>=0;i--) cout<<c[i];
    cout<<endl;
    /*for (int i=0;i<len1;i++) cout<<a[i];
    cout<<endl;
    for (int i=0;i<len2;i++) cout<<b[i];*/
    }
}