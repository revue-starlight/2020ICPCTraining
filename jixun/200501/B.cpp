#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct abc{
    ll a,b;
}a[3];
bool cmp(abc x, abc y){
    if (x.a==y.a) return x.b>y.b;
    else return x.a>y.a;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>a[0].a>>a[0].b>>a[1].a>>a[1].b>>a[2].a>>a[2].b;
        for (int i=0;i<3;i++){
            if (a[i].a<a[i].b) swap(a[i].a,a[i].b);
        }       
        sort(a,a+3,cmp);
       ll  tmpans=(a[0].a*(a[0].b+a[1].b+a[2].b));
        tmpans=min(tmpans, max(a[0].b,max(a[1].b,a[2].b))*(a[0].a+a[1].a+a[2].a) );
        for (int i=0;i<3;i++){
        tmpans=min(tmpans,max(a[i].a,a[(i+1)%3].a+a[(i+2)%3].a) * (a[i].b+max(a[(i+1)%3].b,a[(i+2)%3].b)) );
        tmpans=min(tmpans,max(a[i].a,a[(i+1)%3].a+a[(i+2)%3].b) * (a[i].b+max(a[(i+1)%3].b,a[(i+2)%3].a)) );
        tmpans=min(tmpans,max(a[i].a,a[(i+1)%3].b+a[(i+2)%3].a) * (a[i].b+max(a[(i+1)%3].a,a[(i+2)%3].b)) );
        tmpans=min(tmpans,max(a[i].a,a[(i+1)%3].b+a[(i+2)%3].b) * (a[i].b+max(a[(i+1)%3].a,a[(i+2)%3].a)) );
        tmpans=min(tmpans,max(a[i].b,a[(i+1)%3].a+a[(i+2)%3].a) * (a[i].a+max(a[(i+1)%3].b,a[(i+2)%3].b)) );
        tmpans=min(tmpans,max(a[i].b,a[(i+1)%3].a+a[(i+2)%3].b) * (a[i].a+max(a[(i+1)%3].b,a[(i+2)%3].a)) );
        tmpans=min(tmpans,max(a[i].b,a[(i+1)%3].b+a[(i+2)%3].a) * (a[i].a+max(a[(i+1)%3].a,a[(i+2)%3].b)) );
        tmpans=min(tmpans,max(a[i].b,a[(i+1)%3].b+a[(i+2)%3].b) * (a[i].a+max(a[(i+1)%3].a,a[(i+2)%3].a)) );
        tmpans=min(tmpans,(a[i].a+a[(i+1)%3].b+a[(i+2)%3].b)*max(a[i].b,max(a[(i+1)%3].a,a[(i+2)%3].a)));
        tmpans=min(tmpans,(a[i].a+a[(i+1)%3].b+a[(i+2)%3].a)*max(a[i].b,max(a[(i+1)%3].a,a[(i+2)%3].b)));
        tmpans=min(tmpans,(a[i].a+a[(i+1)%3].a+a[(i+2)%3].b)*max(a[i].b,max(a[(i+1)%3].b,a[(i+2)%3].a)));
        }
        cout<<tmpans<<endl;
    }
}