#include <bits/stdc++.h>
using namespace std;
int n,x;
 priority_queue <int,vector<int>,greater<int> > q;
int main(){
    cin>>n;
    while (n--){
        cin>>x;
        if (x==1) {
            int p;
            cin>>p;
            q.push(p);
        }
        if (x==2) cout<<q.top()<<endl;
        if (x==3) q.pop();
    }
    return 0;
}