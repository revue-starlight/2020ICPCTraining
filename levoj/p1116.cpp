#include <bits/stdc++.h>
using namespace std;
int n;
string s;
string tmp;
int main()
{
	while (cin>>n)
	{
		getline(cin,tmp);
		for (int i=1;i<=n;i++)
		{
			getline(cin,s);
			for (int j=s.length()-1;j>=0;j--)
			cout<<s[j];
			cout<<endl;
		}
	}
	return 0;
}