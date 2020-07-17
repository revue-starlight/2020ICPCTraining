#include <bits/stdc++.h>
using namespace std;
int x_round,y_round,R,rec_1_x,rec_1_y,rec_2_x,rec_2_y,rec_3_x,rec_3_y,rec_4_x,rec_4_y,R;

int check(int x_round,int y_round,int R,int rec_1_x,int rec_1_y,int rec_2_x,int rec_2_y){
    int res=0;
    double x1,y1,x2,y2,x3,y3,x4,y4;
    x1=rec_1_x; y1=rec_1_y;
    x2=rec_1_x; y2=rec_2_y;
    x3=rec_2_x; y3=rec_2_y;
    x4=rec_2_x; y4=rec_1_y;
    
    double dis;
    dis=sqrt(abs(x1-x_round)*abs(x1-x_round)+abs(y1-y_round)*abs(y1-y_round));
    if (dis>(double)R) res++;
    dis=sqrt(abs(x2-x_round)*abs(x2-x_round)+abs(y2-y_round)*abs(y2-y_round));
    if (dis>(double)R) res++;
    dis=sqrt(abs(x3-x_round)*abs(x3-x_round)+abs(y3-y_round)*abs(y3-y_round));
    if (dis>(double)R) res++;
    dis=sqrt(abs(x4-x_round)*abs(x4-x_round)+abs(y4-y_round)*abs(y4-y_round));
    if (dis>(double)R) res++;
    return res;

}

int main(){
    int sorted; //一共有几个点在圆内
    cin>>x_round>y_round>>R>>rec_1_x>>rec_1_y>>rec_2_x>>rec_2_y;
    check(x_round,y_round,R,rec_1_x,rec_1_y,rec_2_x,rec_2_y);
}