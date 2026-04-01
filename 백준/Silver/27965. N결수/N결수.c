#pragma warning(disable:4996)
#include <stdio.h>
#define ll long long

int main(void) {
	ll n, k, t = 0, temp = 0;
	scanf("%lld %lld", &n, &k);
	for (ll i = 1; i <= n; ++i) {
		temp = i;
		while (temp) {
			t *= 10;
			temp /= 10;
		}
		t += i;
		t %= k;
	}
	
	printf("%lld\n", t);
	
	return 0;
}
