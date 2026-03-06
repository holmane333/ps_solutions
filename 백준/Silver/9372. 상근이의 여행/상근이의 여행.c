#include <stdio.h>

int main(void) {
	int tc;
	scanf("%d", &tc);
	for (int test = 0; test < tc; test++) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
		}
		printf("%d\n", n - 1);
	}
	return 0;
}
