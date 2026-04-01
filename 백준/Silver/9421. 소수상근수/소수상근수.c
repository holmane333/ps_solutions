#include <stdio.h>
#include <math.h>
#include <memory.h>
#pragma warning(disable:4996)

int n;
char prime_index[1000001];
int prime[80000], idx = 0;
int v[501], c, temp;

void eratos() {
	int sq = (int)sqrt(1000001);
	prime_index[0] = prime_index[1] = 1;
	for (int i = 2; i <= sq; i++) {
		if (!prime_index[i]) {
			for (int j = i * i; j < 1000001; j += i) {
				prime_index[j] = 1;
			}
		}
	}
    prime[idx++] = 2;
	for (int i = 3; i < 1000001; i += 2) {
		if (!prime_index[i]) {
			prime[idx++] = i;
		}
	}
}

int check(int k) {
	memset(v, 0, sizeof(v));
	c = 0;
	while (1) {
		while (k) {
			temp = k % 10;
			c += temp * temp;
			k /= 10;
		}
		if (c == 1) return 1;
		if (v[c]) return 0;
		v[c] = 1;
		k = c;
		c = 0;
	}
}

int main(void) {
	scanf("%d", &n);
	eratos();
	
	for (int i = 0; i < idx; ++i) {
		if (prime[i] > n) break;
		if (check(prime[i])) printf("%d\n", prime[i]);
	}
	
	return 0;
}
