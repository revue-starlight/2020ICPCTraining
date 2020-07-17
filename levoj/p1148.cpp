#include<bits/stdc++.h>
using namespace std;
const string weeks[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday"};
int main(){
//    freopen("data.in","r",stdin);
//    freopen("data1.out","w",stdout);
    int n,year,month,day,weekday;
    while(cin>>n){
        if (n==-1) continue;
    year=2000;month=1;day=1; 
    weekday=(6+n)%7;  
        for(int i=1;i<=n;i++){
            day=day+1;
           if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
                    if(day==32){
                        month=month+1;
                        day=1;
                    }
                    if(month==13){
                        year=year+1;
                        month=1; 
                    }
           }
            else if (month==2){
                    if((year%4==0&&year%100!=0)||year%400==0){
                        if(day==30){
                            month=month+1;
                            day=1;
                        }
                    }
                    else{
                        if(day==29){
                            month=month+1;
                            day=1;
                        } 
                    }
            }
                else{
                    if(day==31){
                        month=month+1;
                        day=1;
                    }
                    if(month==13){
                        year=year+1;
                        month=1;
                    }
            }
        }
        if(month<10&&day<10){
            cout<<year<<"-"<<0<<month<<"-"<<0<<day<<" "<<weeks[weekday]<<endl;
        }
        else if(month>=10&&day<10){
            cout<<year<<"-"<<month<<"-"<<0<<day<<" "<<weeks[weekday]<<endl;
        }
        else if(month<10&&day>=10){
            cout<<year<<"-"<<0<<month<<"-"<<day<<" "<<weeks[weekday]<<endl;
        }
        else{
            cout<<year<<"-"<<month<<"-"<<day<<" "<<weeks[weekday]<<endl;
        }
    }
    return 0;
}
