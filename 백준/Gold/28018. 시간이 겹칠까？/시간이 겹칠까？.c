#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
	int n, a, b, ary[1000003] = {0, }, q;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &a, &b);
		++ary[a];
		--ary[b + 1];
	}
	for (int i = 1; i < 1000003; ++i) ary[i] += ary[i - 1];
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &a);
		printf("%d\n", ary[a]);
	}
	
	return 0;
}
