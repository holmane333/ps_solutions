#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
	int n, k, a[100010] = {0, }, q[1000010], ft = 0, rr = 0, idx;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= 100000; ++i) a[i] = 1e9;
	q[ft++] = n;
	a[n] = 0;
	while (ft != rr) {
		idx = q[rr++];
		if (rr >= 1000000) rr = 0;
		if (idx + 1 <= 100000) {
			if (a[idx + 1] > a[idx] + 1) {
				a[idx + 1] = a[idx] + 1;
				q[ft++] = idx + 1;
				if (ft >= 1000000) ft = 0;
			}
		}
		if (idx - 1 >= 0) {
			if (a[idx - 1] > a[idx] + 1) {
				a[idx - 1] = a[idx] + 1;
				q[ft++] = idx - 1;
				if (ft >= 1000000) ft = 0;
			}
		}
		if (idx * 2 <= 100000) {
			if (a[idx * 2] > a[idx]) {
				a[idx * 2] = a[idx];
				q[ft++] = idx * 2;
				if (ft >= 1000000) ft = 0;
			}
		}
	}
	printf("%d\n", a[k]);
	return 0;
}
