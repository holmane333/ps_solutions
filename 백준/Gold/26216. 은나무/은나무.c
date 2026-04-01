#pragma warning(diable:4996)
#include <stdio.h>
#include <memory.h>
#define ll long long
#define min(x, y) ((x) > (y) ? (y) : (x))

int main(void) {
	int k, h, q, a[51], b[51], l1, l2;
	ll t1, t2;
	scanf("%d %d %d", &k, &h, &q);
	ll t = 1, tt;
	for (int i = 0; i < h - 1; ++i) t *= k + 1;
	tt = t;
	ll cc = tt * (k + 1);
	while (q--) {
		memset(a, -1, sizeof(a));
		memset(b, -1, sizeof(b));
		l1 = 0;
		l2 = 0;
		a[l1++] = 1;
		b[l2++] = 1;
		scanf("%lld %lld", &t1, &t2);
		if (t1 >= cc || t2 >= cc) {
			puts("-1");
			continue;
		}
		if (t1 == t2) {
			puts("0");
			continue;
		}
		t = tt;
		while (t1) {
			if (t1 % t == 0) {
				break;
			}
			a[l1++] = t1 / t;
			t1 %= t;
			t /= k + 1;
		}
		t = tt;
		while (t2) {
			if (t2 % t == 0) {
				break;
			}
			b[l2++] = t2 / t;
			t2 %= t;
			t /= k + 1;
		}
		int lll = min(l1, l2), idx = 0;
		for (int i = 0; i < lll; ++i) {
			if (a[i] == b[i]) idx = i;
			else break;
		}
		/*for (int i = 0; i < l1; ++i) {
			printf("%d ", a[i]);
		}puts("\n");
		for (int i = 0; i < l2; ++i) {
			printf("%d ", b[i]);
		}puts("\n");
		printf("%d %d %d\n", l1, l2, idx);*/
		printf("%d\n", l1 - 1 - idx + l2 - 1 - idx + 3 - 1);
	}
	
	return 0;
}
