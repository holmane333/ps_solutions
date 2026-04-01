#pragma warning(disable:4996)
#include <stdio.h>
#define ll long long

int main(void) {
	ll n, t = 0;
	scanf("%lld", &n);
	if (n == 2LL) {
		puts("1");
		puts("1 2");
		return 0;
	}
	t = (n - 1) * (n - 2) + n - 1;
	printf("%lld\n", t);
	for (int i = 2; i <= n; ++i) {
		printf("1 %d\n", i);
	}
	return 0;
}
