#include <iostream>
#include <cstring>
using namespace std;
int x[200],y[200];
int main(){
    string a,b;
    while (cin>>a>>b){
        bool bo=true;
        memset(x,0,sizeof(x)); memset(y,0,sizeof(y));
        int l1=a.length(),l2=b.length();
        if (l1!=l2) {cout<<"No"<<endl; continue;}

        for (int i=1;i<l1;i++){
            if (a[i]!=b[i]) {bo=false; break;}
        }

        if (bo) {cout<<"Equal"<<endl; continue;}
        
        for (int i=2;i<l1-1;i++){
            x[a[i]]++;
            y[b[i]]++;
        }
        for (int i=1;i<=200;i++) if (a[i]!=b[i]) {cout<<"No"<<endl;break;}
        
    }
}