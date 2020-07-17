#include <bits/stdc++.h>
using namespace std;
int main(){
    char s;
    int t;
    while (cin>>t){
        while(t--){
            int a,b;
            cin>>s>>a>>b;
            getchar();
            if (s=='-') cout<<a-b<<endl;
            if (s=='+') cout<<a+b<<endl;
            if (s=='*') cout<<a*b<<endl;
            if (s=='/') {double k=(double)a/b; if(fabs(k-(int)k)<1e-8) cout<<a/b<<endl; else printf("%.2lf\n",k);}
        }
    }
}