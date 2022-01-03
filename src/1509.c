#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int n;
long long dp[2502][2502], dp2[2502];
char data[2502];

int palindrome(int start, int end) {
	if (start >= end)
		return 1;

	if (dp[start][end] != -1) 
		return dp[start][end];
	
	if (data[start] != data[end]) {
		dp[start][end] = 0;
		return dp[start][end];
	}

	dp[start][end] = palindrome(start + 1, end - 1);
	return dp[start][end];
}

int main() {
	scanf("%s", data + 1);
	data[0] = '1';
	n = strlen(data) - 1;
	memset(dp, -1, sizeof(dp));
	dp2[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp2[i] = dp2[i - 1] + 1;
		for (int j = 1; j < i; j++) {
			if (palindrome(j, i)) dp2[i] = min(dp2[i], dp2[j - 1] + 1);
		}
	}
	printf("%lld\n", dp2[n]);
	return 0;
}