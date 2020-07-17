#include<iostream>
using namespace std;
 
bool runnian(int year)
{
    if(year%4==0 && year%100!=0 || year%400==0) return 1;
    else return 0;
}
 
int main()
{
    freopen("data.in","r",stdin);
    freopen("data2.out","w",stdout);
    int n;
    while(cin>>n)
    {
        int sum1=0,sum2=0,b,d,year,month,day,weekday;
        int y=2000;
        int c[]= {31,28,31,30,31,30,31,31,30,31,30,31};
        if(n==-1) break;
        weekday=n%7;
        while(sum1<=n)
        {
            b=sum1;
            if(runnian(y)) sum1+=366;
            else sum1+=365;
            y++;
        }
        year=y-1;  ///年份已算出
        ///下面算月份
        if(runnian(year)) c[1]=29;
        for(int i=0; i<12; i++)
        {
            d=sum2;
            sum2+=c[i];
            if(sum2>n-b)    ///必须是>
            {
                month=i+1;  ///月份算出
                break;
            }
        }
        if(d==0) day=n-b+1;
        else day=n-b-d+1;  ///天已算出
        cout<<year<<"-";
        if(month<10) cout<<"0"<<month<<"-";
        else cout<<month<<"-";
        if(day<10) cout<<"0"<<day<<" ";
        else cout<<day<<" ";
        switch(weekday)
        {
        case 0:
            cout<<"Saturday";
            break;
        case 2:
            cout<<"Monday";
            break;
        case 3:
            cout<<"Tuesday";
            break;
        case 4:
            cout<<"Wednesday";
            break;
        case 5:
            cout<<"Thursday";
            break;
        case 6:
            cout<<"Friday";
            break;
        case 1:
            cout<<"Sunday";
            break;
        }
        cout<<endl;
    }
 
    return 0;
}