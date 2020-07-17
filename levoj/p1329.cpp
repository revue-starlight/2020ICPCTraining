#include <bits/stdc++.h>
using namespace std;
int leapyear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}
 
int main(){
	int year;
	int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	while (~scanf("%d",&year))
    {
        int count=0;
        int weeks=4;
	for (int i=1999;i<=year;i++){
        weeks=(weeks+365+leapyear(i-1))%7;
    //    printf("%d %d\n",year,weeks);
    }
    weeks=(weeks+12)%7;
    if (weeks==5) count++;
    for (int i=1;i<12;i++){
        if (i!=2 || !leapyear(year)) weeks=(weeks+m[i])%7;
        else weeks=(weeks+29)%7;
        if (weeks==5) count++; 
    }
    //printf("%d\n",count);
	printf("%d %d\n",year,count);
    }
	return 0;
}