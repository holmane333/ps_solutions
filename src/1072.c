#include <stdio.h>

int main(void) {
	long long x, y;
	scanf("%lld %lld", &x, &y);
	long long z = 100 * y / x;
	if (z >= 99) {
		printf("-1\n");
		return 0;
	}
	long long l = 1, r = 1000000000;
	while (l <= r) {
		long long mid = (l + r) / 2;
		long long t = 100 * (y + mid) / (x + mid);
		if (z >= t) l = mid + 1;
		else r = mid - 1;
	}
	
	printf("%lld\n", l);
	return 0;
}
