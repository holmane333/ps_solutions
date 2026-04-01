#include <stdio.h>
#pragma warning(disable:4996)
#define ll long long

int main(void) {
	ll l, r, k, res = 0LL, v[6] = {0, };
	scanf("%lld %lld %lld", &l, &r, &k);
	for (ll i = 1; i <= k; ++i) {
		ll t = k * (2 + (k - 1) * i) / 2;
		if (v[t % k]) continue;
		v[t % k] = 1;
		if (t > r) break;
		res += (r - t) / k + 1;
		//printf("%lld %lld\n", t, res);
		if (t < l) {
			res -= (l - t) / k;
			if ((l - t) % k) --res;
		}
		//printf("%lld %lld\n", t, res);
	}
	
	printf("%lld\n", res);
	return 0;
}
