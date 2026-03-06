#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
	int q[500020], ft = 0, rr = 0, n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		q[i] = i + 1;
	}
	rr = n;
	while (rr - ft != 1) {
		++ft;
		if (ft >= 500010) ft = 0;
		q[rr++] = q[ft++];
		if (rr >= 500010) rr = 0;
		if (ft >= 500010) ft = 0;
	}
	
	printf("%d\n", q[ft]);
	return 0;
}
