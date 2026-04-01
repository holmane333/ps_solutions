#include <stdio.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable:4996)

long long int dp[102] = { 0,1,1,1,2,2,3,4,5,7,9 };


int DP(int n,int m) {
	if (n == 0) return 0;
	if (dp[m] != 0) return DP(n - 1, m + 1);
	dp[m] = dp[m - 1] + dp[m - 5];
	return DP(n - 1, m + 1);
}

int main() {
	long long int testcase;
	int n;
	scanf("%lld", &testcase);
	for (int i=0;i<testcase;i++){
		scanf("%d", &n);
		if (n <= 10) printf("%lld\n", dp[n]);
		else {
			DP(n - 10, 11);
			printf("%lld\n", dp[n]);
		}
	}
	return 0;
}
