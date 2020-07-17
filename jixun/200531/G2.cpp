#include <bits/stdc++.h>
using namespace std;
struct node{
    int x,y;
};

inline node nd(int a,int b) {node x; x.x=a,x.y=b; return x;}
map <node,int> mp;
vector <node> ans;
int main(){
    string s;
    cin>>s;
    int len=s.length();
    int nx=0,ny=0;

    for (int i=len-1;i>=0;i--){
        if (s[i]=='L'){
            while (mp[nd(nx+1,ny)]!=0) {nx++; mp[nd(nx,ny)]=1; if (nx==0 && ny==0) {cout<<"impossible"<<endl; return 0;}}
            ans.push_back(nd(nx+1,ny));        
        }
        if (s[i]=='R') {
            while (mp[nd(nx-1,ny)]!=0) {nx--; mp[nd(nx,ny)]=1; if (nx==0 && ny==0) {cout<<"impossible"<<endl; return 0;}}
            ans.push_back(nd(nx-1,ny)); 
        }
        if (s[i]=='U') {
            while (mp[nd(nx,ny+1)]!=0) {ny++; mp[nd(nx,ny)]=1; if (nx==0 && ny==0) {cout<<"impossible"<<endl; return 0;}}
            ans.push_back(nd(nx,ny+1)); 
        }
        if (s[i]=='D') {
            while (mp[nd(nx,ny-1)]!=0) {ny--; mp[nd(nx,ny)]=1; if (nx==0 && ny==0) {cout<<"impossible"<<endl; return 0;}}
            ans.push_back(nd(nx,ny-1)); 
        }
    }
    for (int i=0;i<ans.size();i++){
        cout<<ans[i].x<<" "<<ans[i].y<<endl;
    }
    return 0;
}