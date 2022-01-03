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
	int low = 0, high = 0, res = 0;
	long long int sum = prime[0];
	
	while (low <= high && high < idx) {
		if (sum < n) {
			sum += prime[++high];
		}
		else if (sum == n) {
			res++;
			sum += prime[++high];
		}
		else {
			sum -= prime[low++];
		}
	}
	printf("%d\n", res);
	
	return 0;
}