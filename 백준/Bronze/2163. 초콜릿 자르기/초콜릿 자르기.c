#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int dp[300][2];

void swap(int *a, int *b) {
	if (*a < *b) return;
	int t = *a;
	*a = *b;
	*b = t;
	return;
}

int DP(int n, int m) {
	swap(&n, &m);
	if ((n == 1) && (m == 1)) return 0;
	return DP(n, m / 2) + DP(n, m / 2 + m % 2) + 1;
}

int main() {
	int n,m;
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n,&m);

	printf("%d\n", DP(n, m));
	return 0;
}
