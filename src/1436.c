#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int count = 1;

long long int func(long long int m, int n) {
	if (count == n) return m;
	int num = m, result = 0;
	for (int i = 0;; i++) {
		if (num == 0) break;
		if (result >= 3) break;
		if (num % 10 == 6) result++;
		else result = 0;
		num /= 10;
	}
	if (result >= 3) count++;
	return func(m + 1, n);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%lld\n", func(667, n) - 1);
}