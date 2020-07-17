#include<bits/stdc++.h>

#define ll long long

#define MOD 1000000007

using namespace std;

char ch;

ll n,ans,p;

int main() {

	scanf("%lld",&n);

	for(ll i=1; i<=n; i++) {

		scanf(" %c",&ch);

		ll tmp = (1 + i) * i / 2;

		if(ch == '1') p = i;

		tmp -= (i - p + 1) * (i - p) / 2;

		tmp = (tmp % MOD) * p % MOD;

		ans = (ans + tmp) % MOD;

	}

	printf("%lld",ans % MOD);

	return 0;

}