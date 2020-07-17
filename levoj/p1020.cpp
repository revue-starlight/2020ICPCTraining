#include <bits/stdc++.h>
using namespace std;
string s, s1, s2; 
int p,t,maxx,minn;
int main()
{
   
    while (cin >> s) 
    {
        for (int i = 0; i < s.size(); i++)
            if (isalpha(s[i]))
                p = s.size();
            else  break; 

        if (t == 0){
            maxx=minn=p;
            s1=s2=s;  
            t=1;
        }
        if (maxx < p) 
        {
            maxx = p;
            s1 = s; 
        }
        if (minn > p)
        {
            minn = p;
            s2 = s;
        }
    }
    cout << s1 << endl << s2<<endl;
}