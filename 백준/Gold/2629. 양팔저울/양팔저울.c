#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int data[102], dp[101][100003] = { 0, }, N;

void DP(int n, int k) {
	if (n > N) return;
	if (dp[n][k] != -1) return;
	dp[n][k] = 1;
	
	DP(n + 1, k + data[n + 1]);
	DP(n + 1, abs(k - data[n + 1]));
	DP(n + 1, k);
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &data[i]);
	}
	memset(dp, -1, sizeof(dp));
	DP(0, 0);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int data;
		scanf("%d", &data);
		if (data > 30 * 500) {
			printf("N ");
		}
		else if (dp[N][data] != -1) printf("Y ");
		else printf("N ");
	}
	puts("");
	return 0;
}