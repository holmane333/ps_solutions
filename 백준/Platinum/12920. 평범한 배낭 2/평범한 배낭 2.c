#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int dp[100003] = { 0, }, N, w;

int main() {
	int res = 0;
	scanf("%d %d", &N, &w);
	for (int i = 1; i <= N; i++) {
		int v, c, k;
		scanf("%d %d %d", &v, &c, &k);
		int a = 1;
		while (k > 0) {
			a = min(a, k);
			for (int j = w; j >= v * a; --j) // -> 반대로 하면 다 더해짐 
				dp[j] = max(dp[j], dp[j - v * a] + c * a);
			k -= a;
			a <<= 1;
		}
	}
	for (int i = 0; i <= w; ++i) res = max(res, dp[i]);
	printf("%d\n", res);
	return 0;
}