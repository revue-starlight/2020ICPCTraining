#include <bits/stdc++.h>
#define double long double
using namespace std;
double a[4];
const double EPS=1e-6;
int main(){
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    sort(a,a+4);
    double tar_score;
    cin>>tar_score;
    double minn=a[0]+a[1]+a[2];
    minn/=3;
    double maxx=a[1]+a[2]+a[3];
    maxx/=3;
    if (tar_score>=maxx) cout<<"infinite";
    else
        if (tar_score<minn) cout<<"impossible";
    else
    {
        cout<<fixed<<setprecision(2)<<tar_score*3-a[1]-a[2]<<endl;
    }
}