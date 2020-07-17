#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    while (cin>>s1>>s2){
        int a[1000],b[1000],c[1000];
        int len1=s1.length(),len2=s2.length();
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for (int i=0;i<len1;i++) a[len1-1-i]=s1[i]-'0';
        for (int i=0;i<len2;i++) b[len2-1-i]=s2[i]-'0';
        int len;
        if (len1>len2) len=len1; else len=len2;
        for (int i=0;i<len;i++){
            if (a[i]-b[i]<0) {b[i+1]++; c[i]=a[i]-b[i]+10;}
            else c[i]=a[i]-b[i];
        }
        while (c[len-1]==0) len--;
        for (int i=len-1;i>=0;i--) cout<<c[i];
        cout<<endl;

    }
}