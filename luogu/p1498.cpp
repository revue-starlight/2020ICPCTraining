#include <iostream>
using namespace std;

void work(int n)
{
    if (n==1)
    cout<<" /\\";
    cout<<"/__\\";
    else
    {
        cout<<"    ";work(n-1);cout<<endl;
        work(n-1);
    }     
}

int main()
{
    cin>>n;
    work(n);
}