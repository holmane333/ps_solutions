#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))
#define ll long long

int main(void) {
	ll n = 1234567890123LL, e = 1LL, d, res, t = 0, mul = 1;
	int q, a, b;
	scanf("%d", &q);
	
	while (q--) {
		scanf("%d", &a);
		if (a == 0) {
			scanf("%d", &b);
			t += b;
		}
		else if (a == 1) {
			scanf("%d", &b);
			t *= b;
			mul *= b;
		}
		else if (a == 2) {
			scanf("%lld", &d);
			e += d;
		}
		else {
			res = e * mul + t;
			printf("%lld\n", res);
		}
	}
	
	
	return 0;
}
