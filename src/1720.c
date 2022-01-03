#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int dp[251], dp2[251];

int main() {
	int n;
	scanf("%d", &n);
	memset(dp, 0, sizeof(dp));
	
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 3;
	
	dp2[0] = 1;
	dp2[1] = 1;
	dp2[2] = 3;
	
    for (int i = 3; i <= n; i++) dp[i] = dp[i - 1] + 2 * dp[i - 2];
	for (int i = 3; i <= n; i++) {
		if (i % 2 == 0) dp2[i] = (dp[i] + dp[i / 2] + 2 * dp[i / 2 - 1]) / 2;
		else dp2[i] = (dp[i] + dp[i / 2]) / 2;
	}
	printf("%d\n", dp2[n]);
	return 0;
}
