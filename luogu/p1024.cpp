#include <bits/stdc++.h>
using namespace std;

    double a,b,c,d;

double work(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}

int main()
{//1 -84.28 -1593.2125 2121.25
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
   // cout<<work(-2)<<" "<<work(-1.7); 
    int n=0;
    for (int i=-100;i<=99;i++)
    {
        double l,r;
        if (work(i)==0) printf("%.2lf ",(double)i);
        else
        {
            bool bo;
            if (work(i)*work(i+1)<0)
            {
                
                l=i; r=i+1;
                for (n=0;n<=10;n++)
                {
                   bo=true;
                double workl=work(l); double workr=work(r); double k=(l+r)/2;
                 double mid=work((l+r)/2);
                    if (mid==0) {printf("%.2lf ",k); bo=false; break;}
                    else {if (work(l)*mid<0) r=(l+r)/2; 
                                    else l=(l+r)/2;} 
                }
                
                if (bo) printf("%.2lf ",l);
            }
        }
        
    }
    if (work(100)==0) printf("100.00");
    return 0;
}