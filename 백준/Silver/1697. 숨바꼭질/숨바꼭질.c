#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
	int n, k, a[100010] = {0, }, q[1000010], ft = 0, rr = 0, idx;
	scanf("%d %d", &n, &k);
	q[ft++] = n;
	a[n] = 1;
	while (ft != rr) {
		idx = q[rr++];
		if (rr >= 1000000) rr = 0;
		if (idx + 1 <= 100000 && !a[idx + 1]) {
			a[idx + 1] = a[idx] + 1;
			q[ft++] = idx + 1;
			if (ft >= 1000000) ft = 0;
			if (idx + 1 == k) {
				break;
			}
		}
		if (idx - 1 >= 0 && !a[idx - 1]) {
			a[idx - 1] = a[idx] + 1;
			q[ft++] = idx - 1;
			if (ft >= 1000000) ft = 0;
			if (idx - 1 == k) {
				break;
			}
		}
		if (idx * 2 <= 100000 && !a[idx * 2]) {
			a[idx * 2] = a[idx] + 1;
			q[ft++] = idx * 2;
			if (ft >= 1000000) ft = 0;
			if (idx * 2 == k) {
				break;
			}
		}
		
	}
	printf("%d\n", a[k] - 1);
	return 0;
}
