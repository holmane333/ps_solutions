#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
	int q[50020], res[1020], ft = 0, rr = 0, n, k, idx = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		q[i] = i + 1;
	}
	rr = n;
	while (rr != ft) {
		for (int i = 0; i < k - 1; ++i) {
			q[rr++] = q[ft++];
			if (ft >= 50000) ft = 0;
			if (rr >= 50000) rr = 0;
		}
		res[idx++] = q[ft++];
		if (ft >= 50000) ft = 0;
	}
	
	printf("<");
	for (int i = 0; i < n; ++i) {
		printf("%d", res[i]);
		if (i != n - 1) printf(", ");
	}
	puts(">");
	return 0;
}
