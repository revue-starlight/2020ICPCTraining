#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,year,month,day;
    while(cin>>n){
    year=2007;month=10;day=10;    
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
            cout<<year<<"-"<<0<<month<<"-"<<0<<day<<endl;
        }
        else if(month>=10&&day<10){
            cout<<year<<"-"<<month<<"-"<<0<<day<<endl;
        }
        else if(month<10&&day>=10){
            cout<<year<<"-"<<0<<month<<"-"<<day<<endl;
        }
        else{
            cout<<year<<"-"<<month<<"-"<<day<<endl;
        }
    }
    return 0;
}
