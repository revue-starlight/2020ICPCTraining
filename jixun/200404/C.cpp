#include <bits/stdc++.h>
using namespace std;
struct times{
    int start,end,id;
    bool operator < (const times& a) const{
        return start<a.start;
    }
};
map <int,int> mp;
int main(){
    int t;
    cin>>t;
    for (int kaze=1;kaze<=t;kaze++){
        bool bo=true;
        int n;
        cin>>n;
        times a[1004];
        for (int i=1;i<=n;i++){
            cin>>a[i].start>>a[i].end; a[i].id=i;
        }
        sort(a+1,a+1+n);
        int jend=0,cend=0;
        vector <int> vec;
        for (int i=1;i<=n;i++){
            if (a[i].start>=jend) {jend=a[i].end; mp[a[i].id]=0;}
            else {
                if (a[i].start>=cend) {cend=a[i].end; mp[a[i].id]=1;}
                else {bo=0; break;}
            }
        }
        
        cout<<"Case #"<<kaze<<": ";
        if (!bo) {cout<<"IMPOSSIBLE"<<endl;}
        else
        {
            for (int i=1;i<=n;i++) if (mp[i]) cout<<"C"; else cout<<"J";
            cout<<endl;
        }
    }
}