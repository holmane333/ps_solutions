#pragma warning(disable:4996)
#include <stdio.h>
#define COMPARE(x, y)  ( ( (x) < (y) ) ? -1 : ((x) == (y)) ? 0 : 1 )
#define ll long long
#define max(x, y) ((x) > (y) ? (x) : (y))

ll a[250020];
int lower_binary(ll target, int size) {
	int mid, start, end;
	start = 1, end = size;

	while (end > start) {
		mid = (start + end) / 2;
		if (a[mid] < target)
			end = mid;
		else start = mid + 1;
	}
	return end;
}

int main(void) {
	int n, q, f, y;
	ll x;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	a[0] = 1e9 + 1;
	for (int i = 0; i < q; ++i) {
		scanf("%lld %d", &x, &y);
		f = lower_binary(x, n);
		if (a[n] >= x) ++f;
		//printf(" %lld %d\n", a[y], f - 1);
		printf("%lld\n", max(a[y] + (ll)f - x - (ll)y, 0));
	}
	
	return 0;
}
