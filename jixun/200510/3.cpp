#include <bits/stdc++.h>
using namespace std;

int digital(string s){
    int result=0;
    int t=0;
    while (s[t]!='\0'){
        result=result*10+s[t]-'0';
        t++;
    }
    return result;
}
int main(){
    string s;
    int n;
    bool a[1000004];
    memset(a,0,sizeof(a));
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>s;
        int q;
        if (s.length()<7 && s[0]!='-')
        q=digital(s);
        a[q]=1;
    }
    for (int i=0;i<=1000000;i++){
        if (a[i]==0) {cout<<i<<endl; return 0;}
    }
}