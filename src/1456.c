#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define MAX 10000000

long long int prime[MAX + 1];
long long int res[MAX + 1];
int idx = 0;

int main() {
	for (int i = 2; i <= MAX; i++) {
		prime[i] = 1;
	}
	for (long long int i = 2; i * i < MAX; i++) {
		if (prime[i]) {
			for (long long int j = i * i; j < MAX; j += i) {
				prime[j] = 0;
			}
		}
	}
	for (int i = 2; i < MAX; i++) {
		if (prime[i]) res[idx++] = i;
	}

	long long int lt, rt, cnt = 0;
	scanf("%lld %lld", &lt, &rt);

	for (int i = 0; i < idx; i++) {
		long long int n = res[i];
		while (res[i] <= rt / n) {
			if (n * res[i] >= lt) cnt++;
			n *= res[i];
		}
	}
	printf("%lld\n", cnt);
	return 0;
}
