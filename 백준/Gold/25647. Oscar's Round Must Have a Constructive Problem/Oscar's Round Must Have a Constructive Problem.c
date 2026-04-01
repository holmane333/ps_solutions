#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define ll long long
#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int main(void) {
	int tc, n, t, a[100020], res[100020];
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		int c = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i - 1] != a[i]) continue;
			++c;
		}
		if (c == n - 1) {
			puts("NO");
			continue;
		}
		for (int i = 0; i < n; ++i) {
			res[i] = i + 1;
		}
		for (int i = 0; i < n - 1; ++i) {
			if (a[i] == res[i]) {
				swap(res[i], res[n - 1], t);
			}
		}
		if (a[n - 1] == res[n - 1]) {
			c = 0;
			for (int i = 0; i < n - 1; ++i) {
				if (a[n - 1] != res[i] && res[n - 1] != a[i]) {
					c = 1;
					swap(res[i], res[n - 1], t);
					break;
				}
			}
		}
		puts("YES");
		for (int i = 0; i < n; ++i) {
			printf("%d ", res[i]);
		}
		puts("");
	}
	
	return 0;
}
