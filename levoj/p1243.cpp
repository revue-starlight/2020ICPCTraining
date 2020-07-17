#include <bits/stdc++.h>
using namespace std;
struct Country_List{
    string a,b,c,d;
    friend bool operator< (Country_List a,Country_List b){
        return a.b<b.b;
    }
}a[400];
int main(){
    int n;

    while (cin>>n){
    for (int i=0;i<n;i++){
        cin>>a[i].a>>a[i].b>>a[i].c>>a[i].d;
    }
    sort(a,a+n);
    int Chinaa;
    bool bo=false;
    for (int i=0;i<n;i++){
        if (a[i].b=="China") {bo=true; Chinaa=i; continue;}
        cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<" "<<a[i].d<<endl;
    }
    int i=Chinaa;
    if (bo) cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<" "<<a[i].d<<endl;
    }
}