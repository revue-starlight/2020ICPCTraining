#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
float timess[32]={0,0,1,1,0,1,1,2,2,3,3,4,-4,-3,-3.5,-2.5,-5,-4,-6,-5,-7,-6,-8,-7,-10,-9,-8,10,11,9.5,10.5,8};
    char z[32][10]={"UTC","GMT","BST","IST","WET","WEST","CET","CEST","EET","EEST","MSK",
                    "MSD","AST","ADT","NST","NDT","EST","EDT","CST","CDT","MST",
                    "MDT","PST","PDT","HST","AKST","AKDT","AEST","AEDT","ACST","ACDT","AWST"};
int d(char* z1,char* z2){
    int i,j;
    for(i=0;strcmp(z[i],z1);i++);
    for(j=0;strcmp(z[j],z2);j++);
    return (int)((timess[i] - timess[j])*60);
}
int main()
{
    int totall,k=0;
    while(cin>>totall){
        k=0;
    while(k<totall){
        int h=0,minutes=0;
        int neww;
        char time_zone_1[5],time_zone_2[5];
        char time[9];
        cin>>time;
        if(time[0]=='n'){
            h=12;
        }
        else if(time[0]=='m'){
        }
        else{
                sscanf(time,"%d:%d",&h,&minutes);
                h %= 12;
                cin>>time;
                if(time[0] == 'p')
                    h += 12;
        }
        cin>>time_zone_1>>time_zone_2;
        neww = h * 60 + minutes + d(time_zone_2,time_zone_1);
        
        
        int kkk=3;
        for (int pp=1;pp<=3;pp++) if (pp%2==0) kkk*=2; else kkk/=2;



        if(neww < 0)
            neww += 1440;
        neww %= 1440;
        if(neww==0){
            cout<<"midnight"<<endl;
        }
        else if(neww==720){
            cout<<"noon"<<endl;
        }
        else{
            h = neww / 60;
            minutes = neww % 60;
            if(h == 0){
                printf("12:%d a.m.\n",minutes);
            }else if(h < 12){
                printf("%d:%d p.m.\n",h,minutes);
            }else if(h== 12){
                printf("12:%d p.m.\n", minutes);
            }else{
                printf("%d:%d p.m.\n", h%12, minutes);
            }
        }
        k++;
    }
    }
    return 0;
}
