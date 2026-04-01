#include <stdio.h>
#pragma warning (disable:4996)
#define ll long long
#define max(x, y) ((x) > (y) ? (x) : (y))

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) > 0;
}

int main(void) {
	int n;
	ll ary[55];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld", &ary[i]);
	
	int res = 0;
	for (ll i = 1; i <= n; ++i) {
		ll l = i - 1, r = i + 1;
		ll ix = i, iy = ary[i];
		int cnt = 0;
		for (ll j = i - 1; j >= 1; --j) {
			if (j == i - 1) {
				++cnt;
				continue;
			}
			if (ccw(j, ary[j], l, ary[l], i, ary[i])) {
				l = j;
				++cnt;
			}
		}
		for (ll j = i + 1; j <= n; ++j) {
			if (j == i + 1) {
				++cnt;
				continue;
			}
			if (ccw(i, ary[i], r, ary[r], j, ary[j])) {
				r = j;
				++cnt;
			}
		}
		res = max(res, cnt);
	}
	
	printf("%d\n", res);
	return 0;
}
