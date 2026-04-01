#include <stdio.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))
#define ll long long

ll Xor(ll x) {
	x += 1LL;
	ll ary[60] = {0, };
	ll t = 2;
	for (int i = 0; i < 60; ++i) {
		if (x < (t >> 1)) break;
		ary[i] += (x / t) * (t >> 1);
		ary[i] += min((t >> 1), max(0, x % t - (t >> 1)));
		t <<= 1;
	}
	
	ll res = 0LL;
	for (int i = 0; i < 60; ++i) {
		res += ary[i];
	}
	return res;
}

int main(void) {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", Xor(b) - Xor(a - 1));
	
	return 0;
}
