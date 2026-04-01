#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d %d\n", b * 2 - a, b - (b * 2 - a));
	}
	return 0;
}
