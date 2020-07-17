#include <bits/stdc++.h>
using namespace std;
#define MAXN 550001
long long checkone[70002],checktwo[70002];
long long cnta,cntb;
string s;
inline void workone(long long x)
{
    if (s[x]=='o' && s[x+1]=='n' && s[x+2]=='e') checkone[++cnta]=x;
}
inline void worktwo(long long x)
{
    if (s[x]=='t' && s[x+1]=='w' && s[x+2]=='o') checktwo[++cntb]=x;
}
int main()
{
    long long t;
    cin>>t;
    while (t--)
    {
        cnta=0;cntb=0;
        cin>>s;
        for (long long i=0;i<s.length()/3+1;i++) {checkone[i]=0; checktwo[i]=0;}
        for (long long i=0;i<s.length()-2;i++)
        {workone(i);
         worktwo(i);}
        long long ta=1,tb=1;
        vector <long long> v;
        while (ta<=cnta || tb<=cntb)
        {
            if (ta>cnta)
            {
                while (tb<=cntb)
                {v.push_back(checktwo[tb]+1); tb++;}
                break;
            }
            if (tb>cntb)
            {
                while (ta<=cnta)
                {v.push_back(checkone[ta]+1); ta++;}
                break;
            }

            if (checkone[ta]<checktwo[tb])
            {
                v.push_back(checkone[ta]+1); ta++;
            }
            else
            {
                if (checktwo[tb]+2==checkone[ta])
                {v.push_back(checkone[ta]); ta++; tb++;}
                else {v.push_back(checktwo[tb]+1); tb++;}
            }
        }
        cout<<v.size()<<endl;
            for (long long i=0;i<v.size();i++) cout<<v[i]+1<<" ";
        cout<<endl;
    }
}