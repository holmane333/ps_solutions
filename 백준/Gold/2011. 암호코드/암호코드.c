#include <stdio.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)

char data[5002], result[5002] = { 0, };
long long int dp[5002], c = 0, len;

long long int DP(int n) {
	if (n > len) return dp[n - 1];
	if ((int)data[n - 1] - 48 == 0) dp[n] = dp[n - 2];
	else if ((int)data[n - 2] - 48 == 0) dp[n] = dp[n - 1];
	else if (((int)data[n - 2] - 48 == 2) && ((int)data[n - 1] - 48 <= 6)) dp[n] = dp[n - 1] + dp[n - 2];
	else if ((int)data[n - 2] - 48 == 1) dp[n] = dp[n - 1] + dp[n - 2];
	else dp[n] = dp[n - 1];
	dp[n] %= 1000000;
	return DP(n + 1);
}

int main() {
	int k = 1;
	memset(data, 0, sizeof(data));
	dp[0] = 1;
	dp[1] = 1;
	scanf("%s", data);
	len = strlen(data);
	DP(2);
	
	for (int i = 0; i <= len - 2; i++) {
		if ((((int)data[i] - 48 == 0) && ((int)data[i + 1] - 48 == 0)) || (((int)data[i] - 48 >= 3) && ((int)data[i + 1] - 48 == 0))) {
			k = 0;
			break;
		}
	}
	if ((int)data[0] - 48 == 0) printf("%d\n", 0);
	else if (k == 0) printf("%d\n", k);
	else printf("%lld\n", dp[len]);
	return 0;
}