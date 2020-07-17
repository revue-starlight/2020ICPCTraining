#include <iostream>
using namespace std;

void work(int n)
{
	bool bo=false;
	int a[1000],t=0;
	a[1]=0; a[2]=0; a[3]=0;
	while (n!=0) {
		if (n%2==1) a[++t]=1; else a[++t]=0; n/=2;
	}
	for (int i=t;i>3;i--) { 
	if (a[i]==1) 
	{
		if (bo) cout<<"+";
	cout<<"2(";
	work(i-1); 
	cout<<")"; 
	bo=true;}
}
  
    if (a[3]==1) {if (bo) cout<<"+"; cout<<"2(2)"; bo=1;}
    if (a[2]==1) {if (bo) cout<<"+"; cout<<"2"; bo=1;}
    if (a[1]==1) {if (bo) cout<<"+"; cout<<"2(0)"; bo=1;}
}

int main()
{
    int n;
    cin>>n; int t=0;
    int a[1000];
    if (n==0) {
    	cout<<0;
    }
    while (n!=0)
    {
    	if (n%2==1)
    	   	a[++t]=1;
    	else a[++t]=0;
    	n/=2;
    }
    bool bo=false; 
    for (int i=t;i>3;i--)
    {
    	if (a[i]==1) { if (bo) cout<<"+"; cout<<"2(";work(i-1);cout<<")"; bo=true;}
    }

    if (a[3]==1) {if (bo) cout<<"+"; cout<<"2(2)"; bo=1;}
    if (a[2]==1) {if (bo) cout<<"+"; cout<<"2"; bo=1;}
    if (a[1]==1) {if (bo) cout<<"+"; cout<<"2(0)"; bo=1;}
}