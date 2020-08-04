#include<iostream>
using namespace std;
int fib[33]={1,1};
int  main()
{ 
    for (int i=2;i<=32;i++) fib[i]=fib[i-1]+fib[i-2];
    cout<<fib[31]<<fib[32];
}