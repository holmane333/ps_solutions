#include <stdio.h>
#pragma warning(disable:4996)
#define ll long long
#define max(x, y) ((x) > (y) ? (x) : (y))

int main(void) {
	int n, m;
	ll k, d, a, t, l[110][5];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		t = 0;
		scanf("%d", &m);
		for (int j = 0; j < m; ++j) {
			scanf("%lld %lld %lld", &l[j][0], &l[j][1], &l[j][2]);
		}
		scanf("%lld %lld %lld", &k, &d, &a);
		for (int j = 0; j < m; ++j) {
			t += max(0, l[j][0] * k - l[j][1] * d + l[j][2] * a);
		}
		printf("%lld\n", t);
	}
	return 0;
}
