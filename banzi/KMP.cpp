void Getnxt(char *s){
    int i=0,j=-1,len=strlen(s);
    nxt[0]=-1;
    while (i<len){
        if (j==-1 || s[i]==s[j]){
            i++;
            j++;
            nxt[i]=j;
        }
        else j=nxt[j];
    }
}

int kmp(char *s,char *p){
    int i=0,j=0,lens=strlen(s),lenp=strlen(p);
    whle (i<lens && j<lenp){
        if (j==-1 || s[i]==p[j]){
            i++; j++;
        }
        else j=nxt[j];
    }
    if (j==lenp) return i-lenp;
    else return
}
//用于输出nxt数组的板子
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 25;
char s[N],p[M];
int nxt[N];
void Getnxt(char *s){
    int i=0,j=-1,len=strlen(s);
    nxt[0]=-1;
    while (i<len){
        if (j==-1 || s[i]==s[j]){
            i++;
            j++;
            nxt[i]=j;
        }
        else j=nxt[j];
    }
}
int main(){
    scanf("%s",s);
    for (int i=0;i<strlen(s);i++) printf("%2c",s[i]);
    Getnxt(s);
    printf("\n");
    for (int i=0;i<strlen(s);i++) printf("%2d",nxt[i]);
}
*/