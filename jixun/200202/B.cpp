#include<bits/stdc++.h>
using namespace std;
char a[1000000];
int main() {
    int ex=0;
    scanf("%c.%[0-9]e%d",&a[0],a+1,&ex);
    int f=0;
    for(int i=1; a[i]; i++) {
        if(a[i]!='0') {
            f=1;
        }
    }
    if(!f&&!ex)
        printf("%c",a[0]);
    else {
        for(int i=0; i<ex+1||a[i]; i++) {
            if(i==ex+1) printf(".");
            printf("%c",!a[i]?'0':a[i]);
        }
    }
    return 0;
}