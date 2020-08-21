#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[]={1,3,2};
    double sum=0;
    for (int i=0;i<3;i++)
     for (int j=0;j<3;j++)
    {
        double tmp=0;
        for (int k=min(i,j);k<=max(i,j);k++)
            tmp+=a[k];
        sum+=tmp/(j-i+1);
    }
    cout<<sum<<endl;
}