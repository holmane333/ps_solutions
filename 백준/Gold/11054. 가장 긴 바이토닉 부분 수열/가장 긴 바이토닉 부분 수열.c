#include <stdio.h>
#include <memory.h>
#include <math.h>
#pragma warning(disable:4996)

int dp1[1002] = { 0, }, dp2[1002] = { 0, };
int data[1002];

int DP1(int n) {
	int result = 1, x = data[n];

	for (int i = 1; i < n + 1; i++) {
		if ((x > data[i]) && (result <= dp1[i])) {
			result = dp1[i] + 1;
		}
	}
	dp1[n] = result;
	return result;
}


int DP2(int k,int n) {
	int result = 1, x = data[k];

	for (int i = n; i >= k; i--) {
		if ((x > data[i]) && (result <= dp2[i])) {
			result = dp2[i] + 1;
		}
	}
	dp2[k] = result;
	return result;
}


int main() {
	int n;
	memset(data, -1, sizeof(data));
	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++) {
		scanf("%d", &data[i]);
	}
	int max1 = 0, max2 = 0, max = 0, result1, result2;
	for (int i = 1; i <= n; i++) {
		result1 = DP1(i);
	}
	for (int i = n; i >= 1; i--) {
		result2 = DP2(i, n);
	}
	for (int i = 1; i <= n; i++) {
		max = max > (dp1[i] + dp2[i] - 1) ? max : (dp1[i] + dp2[i] - 1);
	}
	printf("%d\n", max);
	return 0;
}
