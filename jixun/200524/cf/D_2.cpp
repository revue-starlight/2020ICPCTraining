#include<iostream>   
using namespace std;      
#define long long long
const long N = 100000;     
long prime[N] = {0},num_prime = 0;      
int isNotPrime[N] = {1, 1};//先将0，1排除 
int main()      
{        
        for(long i = 2 ; i < N ; i ++)         
        {              
        if(! isNotPrime[i])            
            prime[num_prime ++]=i; 
        for(long j = 0 ; j < num_prime/*小于已经求出的质数个数*/ && i * prime[j]/*乘以其它质数，且质数比自己小或者是自己（已经求出来了），所以不可能重复*/ <  N ; j ++)  
            {                 
                isNotPrime[i * prime[j]] = 1;//乘以其它素数得到的一定是合数，之所以不重复是因为质数间不等 
            if( !(i % prime[j] ) )  //关键处2 i%prime==0  根据“关键处2”的定义，当p1==prime[j] 的时候，
            //筛除就终止了(从最小质数开始所以本句话成立），            
                break;             
        }          
    }          
    //for (int i=0;i<num_prime;i++) cout<<prime[i]<<endl;
    int t;
    cin>>t;
    while (t--){
        int n,k;
        cin>>n>>k;
        int ans=n;
        for (int i=0;i<num_prime;i++){
            if (prime[i]>k) break;
            else if (n%prime[i]==0) ans=n/prime[i];
        }
        cout<<ans<<endl;
    }
 }