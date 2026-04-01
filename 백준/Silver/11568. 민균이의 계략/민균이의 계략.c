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
	int n;
	scanf("%d", &n);
	int ary[1001], dp[1001], max = INT_MIN;
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (ary[j] < ary[i]) dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
		}
		max = max > dp[i] ? max : dp[i];
	}
	
	printf("%d\n", max);

	return 0;
}
