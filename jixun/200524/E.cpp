#include <bits/stdc++.h>
using namespace std;
#define double long double
double a[4];
const double EPS = 1e-6;
int main(){
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    sort(a,a+4);
    double tar_score;
    cin>>tar_score;
    double minn=a[0]+a[1]+a[2];
    double maxx=a[1]+a[2]+a[3];
    if (tar_score*3>=maxx+EPS) cout<<"infinite";
    else
        if (minn>=tar_score*3+EPS) cout<<"impossible";
    else
    {
        cout<<fixed<<setprecision(2)<<tar_score*3-a[1]-a[2]<<endl;
    }
}