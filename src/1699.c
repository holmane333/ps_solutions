#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int dp[100001];

int main() {

	int N;
	scanf("%d", &N);

	dp[0] = 0; dp[1] = 1;

	for (int i = 0; i <= N; i++)
		dp[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	printf("%d", dp[N]);
}