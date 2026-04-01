#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

char s[50];
int dp[50][4], len;

int main() {
	scanf("%s", s);
	len = (int)strlen(s);
	
	dp[1][1] = 1;

	int prev = (int)(s[0] - '0') * 10;

	for (int i = 2; i <= len; i++) {
		int v = (int)(s[i - 1] - '0');
		if (v == 0) {
			if (prev + v <= 34) dp[i][2] = dp[i - 1][1];
			continue;
		}
		dp[i][1] = dp[i - 1][1] + dp[i - 1][2];
		if (prev + v <= 34) dp[i][2] = dp[i - 1][1];
		
		prev = v * 10;
	}
	printf("%d\n", dp[len][1] + dp[len][2]);
	return 0;
}
