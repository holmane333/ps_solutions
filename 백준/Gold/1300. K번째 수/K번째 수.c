#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define ll long long
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

ll n, k;

int cmp(const void *a, const void *b) {
	return *(ll*)a > *(ll*)b;
}

int check(ll h) {
	ll t = 0LL;
	for (ll i = 1; i <= n; i++) {
		t += min(n, h / i);
	}
	//printf("%lld %lld %lld\n", h, k, t);
	//printf("%lld ", t);
	return t >= k;
}

int main(void) {
	scanf("%lld %lld", &n, &k);
	
	ll left = 1, right = k, res = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		int r = check(mid);
		//printf("%lld %d\n", mid, r);
		if (r) {
			res = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	//printf("%lld %lld\n", left, right);
	printf("%lld\n", res);
	return 0;
}
