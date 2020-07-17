#include <bits/stdc++.h>
using namespace std;
string s[]={"UTC","GMT","BST","IST","WET","WEST","CET","CEST","EET","EEST"
,"MSK","MSD","AST","ADT","NST","NDT","EST","EDT","CST","CDT","MST","MDT",
"PST","PDT","HST","AKST","AKDT","AEST","AEDT","ACST","ACDT","AWST"};
float utc[]={0,0,1,1,0,1,1,2,2,3,3,4,-4,-3,-3.5,-2.5,-5,-4,-6,-5,-7,-6,-8,-7,-10,-9,-8,10,11,9.5,10.5,8};

int main(){
    int n;
    while (cin>>n){
        for (int i=1;i<=n;i++){
            string tmp;
            cin>>tmp;
            //initialize
            int hour=0,minute=0;
            if (tmp[0]=='n') hour=12,minute=0;
            else if (tmp[0]=='m') hour=0,minute=0;
            else{
                int x=0;
                while (tmp[x]!=':') {
                    hour=hour*10+tmp[x]-48;
                    x++;
                }
                x++;
                while (tmp[x]!='\0'){
                    minute=minute*10+tmp[x]-48;
                    x++;
                }
                cin>>tmp;
                if (tmp=="a.m."){
                    if (hour==12) hour=0;
                }
                if (tmp=="p.m."){
                    hour+=12;
                    if (hour==24) hour=12;
                }
            }

            string tz1,tz2;
            cin>>tz1>>tz2;
            
            int time_zone_1,time_zone_2;
            for (int i=0;;i++){
                time_zone_1=utc[i];
                if (tz1==s[i]) break;
            }
            for (int i=0;;i++){
                time_zone_2=utc[i];
                 if (tz2==s[i]) break;
            }
            
            double delta=time_zone_2-time_zone_1;
            if (delta==(int)delta){
                hour+=delta;
            }
            else {
                hour+=(int)delta;
                if (delta>0) minute+=30; else minute-=30;
            }
            if (minute>=60) {hour++; minute-=60;}
            if (hour>=24) {hour-=24;}

            if (minute<0) {minute=60+minute; hour--;}
            if (hour<0) hour+=24;

            if (hour==0){
                if (minute==0) cout<<"midnight"<<endl;
                else cout<<12<<":"<<minute<<" a.m."<<endl;
            }
            else if (hour<12){
                cout<<hour<<":"<<minute<<" a.m."<<endl;
            }
            else if (hour==12){
                if (minute==0) cout<<"noon"<<endl;
                else cout<<hour<<":"<<minute<<" p.m."<<endl;
            }
            else{
                cout<<hour-12<<":"<<minute<<" p.m."<<endl;
            }

        }
    }        
}