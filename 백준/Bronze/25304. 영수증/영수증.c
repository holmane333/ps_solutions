#include <stdio.h>
#pragma warning(disable:4996)
#define ll long long

int main(void) {
	ll x, n, a, b, t = 0;
	scanf("%lld %lld", &x, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld %lld", &a, &b);
		t += a * b;
	}
	if (x == t) printf("Yes\n");
	else printf("No\n");
	return 0;
}
