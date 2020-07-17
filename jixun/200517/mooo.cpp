#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
const ll Max = 5e5 + 10;
ll n;
ll sum;
ll alt[Max],a[Max];
void merge(ll l, ll r)
{
    for(int i= l; i <= r; i ++)
        alt[i] = a[i];
    ll mid = (l + r) >> 1;
    ll i = l, j = mid + 1;
    for (ll pos = l; pos <= r; pos++)
    {
        if (i == mid + 1)
        {
            a[pos] = alt[j];
            j++;
        }
        else if (j == r + 1)
        {
            a[pos] = alt[i];
            i++;
        }
        else if (alt[i] > alt[j])
        {
            a[pos] = alt[j];
            j++;
            sum += mid - i + 1;       
        }
        else
        {
            a[pos] = alt[i];
            i++;
        }
    }
}

void merge_sort( ll l, ll r)
{
    if (l == r)
        return;
    ll mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, r);
}

int main()
{
    sum = 0;
    while (cin>>n){
        sum=0;
            if (n==0)return 0;
    for (ll i = 0; i < n; i++) cin>>a[i];
    merge_sort(0, n - 1);
    printf("%lld\n", sum);
    
    }
}