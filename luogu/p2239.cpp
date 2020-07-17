#include <bits/stdc++.h>
using namespace std;
#define ll long long
int x,y,n;
ll sum;
int main()
{
    cin>>n>>x>>y;
    int layer=min(min(n-y+1,n-x+1),min(x,y));
  //  cout<<"layer="<<layer<<endl;
            layer--;
            if (n%2==1)
                sum=((n/2)*4+((n/2)-layer+1)*4)*layer;
            else
            {
                 sum=4*(n-layer)*layer;
            }
            
    //        cout<<"sum="<<sum<<endl;
            if (x==layer+1)  {//cout<<"x==layer+1  "; 
                                cout<<sum+1+0*(n-2*layer-1)+y-(layer+1); return 0;  }
            if (n-y+1==layer+1) {//cout<<"n-y+1==layer+1 ";
                                cout<<sum+1+1*(n-2*layer-1)+x-(layer+1); return 0;}
            if (n-x+1==layer+1) {//cout<<"n-x+1==layer+1 "; 
                                    cout<<sum+1+2*(n-2*layer-1)+(n-y+1)-(layer+1); return 0;}
            cout<<sum+1+3*(n-2*layer-1)+(n-x+1)-(layer+1)<<endl; return 0;
}