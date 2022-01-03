#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (y) : (x))

int main(void) {
	long long d, p, q;
	scanf("%lld %lld %lld", &d, &p, &q);
	if (p < q) {
		long long temp = p;
		p = q;
		q = temp;
	}
	if (!(d % p) || !(d % q)) {
		printf("%lld\n", d);
		return 0;
	}
	long long len = d / p + 1LL;
	long long res = p * len;
	for (long long i = len - 1; i >= 0LL; --i) {
		if ((d - p * i) % q == 0) {
			printf("%lld\n", d);
			return 0;
		}
		long long t = (d - p * i) / q + 1;
		t = p * i + t * q;
		if (t == res) break;
		res = min(res, t);
	}
	
	printf("%lld\n", res);
	
	return 0;
}
