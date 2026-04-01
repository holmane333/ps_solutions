#include <stdio.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define ll long long

int main(void) {
	int n;
	ll a, s, res = 0, m = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a);
		m = max(m, a);
		if (!i) s = a;
		else {
			if (s < a) res += a - s;
			s = a;
		}
	}
	
	res += m - s;
	printf("%lld\n", res);
	return 0;
}
