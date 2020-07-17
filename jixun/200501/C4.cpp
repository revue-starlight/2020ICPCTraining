#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x;
    cin>>n>>m>>x;
    if (x%n==0 || x%m==0) {cout<<1<<endl; return 0;}
    bool flg = false;
    for(int i = 1; i <= min(n, m); i++)
    {
        int a = i;
        //cout << a << endl;
        if(x % a == 0)
        {
            int b = x / a;
            if(max(a, b) < max(m, n) && min(a, b) < min(m, n))
            {
                cout << "2" << endl;
                flg = true;
                return 0;
            }
        }
    }
    x = n * m - x;
    for(int i = 1; i <= min(n, m); i++)
    {
        int a = i;
        //cout << a << endl;
        if(x % a == 0)
        {
            int b = x / a;
            if(max(a, b) < max(m, n) && min(a, b) < min(m, n))
            {
                cout << "2" << endl;
                flg = true;
                return 0;
            }
        }
    }
    if(!flg)
        cout<<3<<endl;
}