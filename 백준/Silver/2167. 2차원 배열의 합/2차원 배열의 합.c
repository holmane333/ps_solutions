#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int data[302][302];
int dp[302][302] = { 0, };

int main() {
	int n,m,testcase;
	int x1, y1, x2, y2;
	long long int result;
	scanf("%d %d", &n, &m);
	memset(data, -1, sizeof(data));
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m+1; j++) {
			scanf("%d", &data[i][j]);
		}
	}
	for (int i = 1; i < n+1; i++) {
		for (int j = 1; j < m + 1; j++) {
			dp[i][j] = data[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	scanf("%d", &testcase);
	
	for (int i = 0; i < testcase; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		result = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		printf("%d\n", result);
	}


	return 0;
}
