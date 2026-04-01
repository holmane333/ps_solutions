#include <stdio.h>
#pragma warning (disable:4996)

int prime_i[1000010], prime[1000010], idx;

void eratos() {
	prime_i[0] = prime_i[1] = 1;
	for (int i = 2; i * i <= 1000000; ++i) {
		if (!prime_i[i]) {
			for (int j = i * i; j <= 1000000; j += i) {
				prime_i[j] = 1;
			}
		}
	}
	for (int i = 2; i <= 1000000; ++i) {
		if (!prime_i[i]) prime[idx++] = i;
	}
}

int main(void) {
	int n, t = 0;
	scanf("%d", &n);
	if (n < 8) {
		printf("-1\n");
		return 0;
	}
	t = n & 1;
	
	n -= 4 + (n & 1);
	eratos();
	for (int i = 0; i < idx; ++i) {
		if (n <= prime[i]) break;
		if (!prime_i[n - prime[i]]) {
			printf("%d %d %d %d\n", 2, 2 + t, prime[i], n - prime[i]);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}
