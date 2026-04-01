#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int fibo[43] = { 1,2 };

int main() {
	int tc, n;
	scanf("%d", &tc);
	for (int i = 2; i < 43; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
	for (int t = 0; t < tc; t++) {
		scanf("%d", &n);
		int ary[1000], idx = 0;

		while (n) {
			int i;
			for (i = 0; i < 43; i++) {
				if (fibo[i] > n) break;
			}
			i--;
			i = i < 0 ? 0 : i;
			ary[idx++] = fibo[i];
			n -= fibo[i];
		}

		for (int i = idx - 1; i >= 0; i--) {
			printf("%d ", ary[i]);
		}
		puts("");
	}
	
	return 0;
}
