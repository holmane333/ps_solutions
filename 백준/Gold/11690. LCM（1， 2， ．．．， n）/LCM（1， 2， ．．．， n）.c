#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

const long long mod = (long long)1 << 32;
int n;
char prime_index[100000001];
int prime[6000000], idx = 0;

void eratos() {
	int sq = (int)sqrt(100000001);
	prime_index[0] = prime_index[1] = 1;
	for (int i = 2; i <= sq; i++) {
		if (!prime_index[i]) {
			for (int j = i * i; j < 100000001; j += i) {
				prime_index[j] = 1;
			}
		}
	}
    prime[idx++] = 2;
	for (int i = 3; i < 100000001; i += 2) {
		if (!prime_index[i]) {
			prime[idx++] = i;
		}
	}
}

int main() {
	scanf("%d", &n);
	eratos();
	
	long long res = 1LL;
	for (int i = 0; i < 6000000; ++i) {
		if (prime[i] > n) break;
		long long p = (long long)prime[i];
		while (p * prime[i] <= n) p *= prime[i];
		res = (res * p) % mod;
	}
	
	printf("%lld\n", res);
	return 0;
}