#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
vector <int> vec[100];
const int maxn=1e5+1;
const maxai=2*1e5+1;
int n;
int a[maxn];
int prime[maxn/2];
//引入一个素数筛*欧拉筛，用于筛选素数。
//记忆筛法：
// 
void Decompositon(int x){

}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++){
        Decomposition(a[i]);
    }   
}