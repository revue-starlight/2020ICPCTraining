#include <bits/stdc++.h>
using namespace std;
const int maxn=6e5+10;
queue <int> q;
struct ACautomation{
    struct Node{
    int fail,cnt,last,typ,next[26];
    }tree[maxn];
    int tot;
    void init(){
        tree[0].cnt=tree[0].last=0;
        for (int i=0;i<26;i++) tree[0].next[i]=0;
        int tot=0;
        tree[0].fail=-1;
        while (!q.empty()) q.pop();
    }

    void insert(string s,int typ){
        int len=s.length();
        int now=0;
        for (int i=1;i<=n;i++){
            char ch=s[i]-'a';
            if (tree[now].next[])
        }
    }
}
int main(){
    
}