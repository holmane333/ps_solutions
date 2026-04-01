#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int func(int n,int m) {
	if (n == m) return 0;
	int sum = m, i = m;
	for (int j = 0;; j++) {
		if (i == 0) break;
		sum += i % 10;
		i /= 10;
	}
	if (sum == n) return m;
	return func(n, m + 1);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", func(n, 1));
}