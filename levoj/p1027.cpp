#include <bits/stdc++.h>
using namespace std;
int n;
bool b[30];
int check(int k){
    int sum=2*n,left=0;
    int now=0,hit=0;
    int start=1;
    while (1){
        now=start+k-1;
        now%=sum;
        if (now>n || now==0){
            hit++;
            if (hit==n) return 1;
            sum--;
            if (now==0) start=1;
            else start=now;
        }
        else return 0;
    }
}

int main(){
    while (cin>>n){
        int p=n+1;
        while (1){
            if (check(p)) {cout<<p<<endl; break;}
            p++; 
        }
    }
}