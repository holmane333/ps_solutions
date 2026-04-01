#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int prime[3000001];

int main() {
	for (int i = 2; i < 3000001; i++) prime[i] = 1;
	for (int i = 2; i * i <= 3000000; i++) {
		if (prime[i]) {
			for (int j = i * i; j < 3000001; j += i) {
				prime[j] = 0;
			}
		}
	}

	int tc;
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++) {
		int n;
		scanf("%d", &n);
		if (prime[n]) printf("0\n");
		else {
			int i = n, j = n;
			while (!prime[i]) i--;
			while (!prime[j]) j++;
			printf("%d\n", j - i);
		}
	}


	return 0;
}
