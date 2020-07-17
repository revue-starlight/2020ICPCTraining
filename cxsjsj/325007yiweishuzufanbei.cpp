#include <bits/stdc++.h>
using namespace std;

void fanbei(int a[],int n){
    for (int i=0;i<3;i++){
        a[i]*=2;
    }
}
int main(){
    int set[]={1,2,3};
    fanbei(set,3);
    for (int i=0;i<3;i++)
        cout<<set[i]<<" ";
}