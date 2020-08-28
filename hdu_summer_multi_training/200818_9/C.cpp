#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a, b,k;
    int c;
    
    int t;
    cin>>t;
    while (t--)
    {cin >> a >> b>>k;
        if (a > b) swap(a, b);
        int m=(b-a);

        k++;
        long double x=m/k*((sqrt(4.0+k*k) + 2-k) / 2));
        
        if (c == a) cout << "0" << endl;
        else cout << "1" << endl;
        
   }
    return 0;
}