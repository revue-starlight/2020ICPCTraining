#include <bits/stdc++.h>
using namespace std;

string pre_order,in_order;

void output(int pre_L,int pre_R,int in_L,int in_R)
{
    int in_M;
    if(pre_L>pre_R) return ;
    if(pre_L==pre_R)
    {
        cout<<pre_order[pre_L];
        return ;
    }
    in_M=in_order.find(pre_order[pre_L]);
    output(pre_L+1,pre_L+in_M-in_L,in_L,in_M-1);
    output(pre_L+in_M-in_L+1,pre_R,in_M+1,in_R);
    output(pre_L,pre_L,in_M,in_M);
}

void work()
{
    int in_L,in_R,pre_L,pre_R;
    pre_L=in_L=0;pre_R=in_R=pre_order.length()-1;
    output(pre_L,pre_R,in_L,in_R);
}

int main()
{
    cin>>in_order>>pre_order;
    work();
    printf("\n");
    return 0;
}