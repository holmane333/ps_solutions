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
int dp[2002][2002], data[2002];

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
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &data[i]);
	}
	int t;
	scanf("%d", &t);
	int start, end;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &start, &end);
		printf("%d\n", palindrome(start, end));
	}
}