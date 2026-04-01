#include <stdio.h>
#pragma warnint(disable:4996)

int r1 = 0;

void f1(int n) {
	if (n == 1 || n == 2) {
		++r1;
		return;
	}
	f1(n - 1);
	f1(n - 2);
}

int main(void) {
	int n, f[55] = {1, 2};
	scanf("%d", &n);
	for (int i = 2; i <= 50; ++i) f[i] = f[i - 1] + f[i - 2];
	printf("%d %d\n", f[n - 2], n - 2);
	return 0;
}
