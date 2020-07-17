#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int main(){
    int t;
    while (cin>>t){
        
        
        while (t--){
                while (v.size()) v.pop_back();
                int a,maxx=-0x3f3f3f3f,minn=0x3f3f3f3f;
                double ans=0;
                while (cin>>a){
                    if (a==-1) break;
                    if (a>maxx) maxx=a;
                    if (a<minn) minn=a;
                    v.push_back(a);
                    ans+=a;
                }
                ans=ans/v.size();
                cout<<v.size()<<endl<<maxx<<endl<<minn<<endl;
                printf("%.1lf\n",ans);
        }
    
    
    
    
    
    
    
    
    
    }
}