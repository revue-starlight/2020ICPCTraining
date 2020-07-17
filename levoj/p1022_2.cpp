#include <cstdio>
#include <algorithm>
using namespace std;

int y, m, d, yy = 2007, mm = 10, dd = 10, flag = 1, cnt;
int ddd[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int judge(int x) {
    if(!(x % 100)) {
        if(x % 400) return 0;
        return 1;
    }
    if(x % 4)   return 0;
    return 1;
}

int main() {
    scanf("%d%d%d", &y, &m, &d);
    if(y != 2007 && y > 2007)   flag = -1;
    else if(m != 10 && m > 10)    flag = -1;
    else if(d != 10 && d > 10)  flag = -1;
    if(flag == -1)  swap(y, yy), swap(m, mm), swap(d, dd),flag=1;
//  printf("%d %d %d %d %d %d", y, m, d, yy, mm, dd);
    while(1) {
//      printf("Today is %d.%d.%d\n", y, m, d);
        if(d == dd && m == mm && y == yy) break;
        cnt++;
        if(flag == -1) {
            d--;
            if(d < 1) {m--; d = ddd[m] + (judge(y) && m == 2 ? 1 : 0);}
            if(m < 1) {y--; m = 12; d = 31;}
        } else {
            d++;
            if(d > ddd[m] + (judge(y) && m == 2 ? 1 : 0)) {m++; d = 1;} 
            if(m > 12) {y++; m = 1;}
        }
    }
    printf("%d\n", cnt);
    return 0;
}