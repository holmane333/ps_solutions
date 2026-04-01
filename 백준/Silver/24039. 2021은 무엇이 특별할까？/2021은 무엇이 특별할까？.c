#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int n;
int prime_index[4000001], prime[283147], idx = 0;

void eratos() {
	int sq = (int)sqrt(4000001);
	prime_index[0] = prime_index[1] = 1;
	for (int i = 2; i <= sq; i++) {
		if (!prime_index[i]) {
			for (int j = i + i; j < 4000001; j += i) {
				prime_index[j] = 1;
			}
		}
	}
	for (int i = 2; i < 4000001; i++) {
		if (!prime_index[i]) {
			prime[idx++] = i;
		}
	}
}

int main() {
	scanf("%d", &n);
	eratos();
	
	for (int i = 0; i < idx; ++i) {
		if (prime[i] * prime[i + 1] > n) {
			printf("%d\n", prime[i] * prime[i + 1]);
			return 0;
		}
	}
	
	return 0;
}