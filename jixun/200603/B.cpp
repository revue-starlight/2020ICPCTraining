#include <bits/stdc++.h>
using namespace std;      
const long N = 200000;     
long prime[N] = {0},num_prime = 0;      
int isNotPrime[N] = {1, 1};
int a[150001][2];
map <int,int> ans;
int maxx;
int real_ans;
inline void work(int x,int y){
    vector <int> vec;
    map <int,int> mp;
    while (x!=1){
        for (int i=0;i<=5000;i++){
            if (x%prime[i]==0){
                if (!mp[i]) vec.push_back(prime[i]);
                mp[i]++;
                x/=prime[i];
                break;
            }
        }
    }
    while (y!=1){
        for (int i=1;i<=5000;i++){
            if (y%prime[i]==0){
                if (!mp[i]) vec.push_back(prime[i]);
                mp[i]++;
                y/=prime[i];
                break;
            }
        }
    }
    for (int i=0;i<vec.size();i++){
         ans[vec[i]]++; 
         if (maxx<=ans[vec[i]]) {real_ans=vec[i]; maxx=ans[vec[i]];}
         }
}
int main()      
{        
        for(int i = 2 ; i < N ; i ++)         
        {              
        if(! isNotPrime[i])          
            prime[num_prime ++]=i;
            for(int j=0;j<num_prime&&i*prime[j]<N;j++)  
            {                 
                isNotPrime[i*prime[j]]=1;
            if(!(i % prime[j]))  
                break;
        }          
    }       

   cout<<prime[5000]<<endl;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
        work(a[i][0],a[i][1]);
    }
    if (maxx==n) cout<<real_ans<<endl; else cout<<-1<<endl;
 }