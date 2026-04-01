#pragma warning(disbale:4996)
#include <stdio.h>

int main(void) {
	int n, a[210] = {0, }, b;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b);
		++a[b + 100];
	}
	scanf("%d", &b);
	printf("%d\n", a[b + 100]);
	return 0;
}
