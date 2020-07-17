#include <bits/stdc++.h>
using namespace std;

int a[1000];
int k[1000];
int b[1000];
int main(){
   char ch;
   int n,m;
   cin>>n>>m;
   for (int i=m-n+1;i<=m;i++){
       cin>>ch;
       a[i]=ch-'a';
   }
   for (int i=1;i<=m;i++){
       cin>>ch;
       b[i]=ch-'a';
   }
   for (int i=m;i>n;i--){
       if (b[i]>a[i]) k[i]=b[i]-a[i];
       else k[i]=(b[i]+26)-a[i];
       a[i-n]=k[i]%26;
   }
   for (int i=1;i<=m;i++){
       cout<<(char)(a[i]+'a');
   }
   cout<<endl;
}