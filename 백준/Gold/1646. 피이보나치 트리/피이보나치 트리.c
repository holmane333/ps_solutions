#include <stdio.h>
#pragma warning (disable:4996)
#define ll long long

int n;
ll dp[60], l, r;

void DP(int n, ll l, ll r) {
	//printf("%d %lld %lld\n", n, l, r);
	if (l == r && l == 1) return;
	if (n <= 1) return;
	
	if (l <= 1 + dp[n - 2] && r <= 1 + dp[n - 2] && l != 1 && r != 1) { // 왼쪽에 두 개 다 있음: 출력 X, 재귀로 내려가기
		DP(n - 2, l - 1LL, r - 1LL);
	}
	else if (l > 1 + dp[n - 2] && r > 1 + dp[n - 2] && l != 1 && r != 1) { // 오른쪽에 두 개 다 있음: 출력 X, 재귀로 내려가기
		DP(n - 1, l - 1LL - dp[n - 2], r - 1LL - dp[n - 2]);
	}
	else {
		if (l == 1) {
			if (r > 1 + dp[n - 2]) {
				printf("R");
				DP(n - 1, 1, r - 1LL - dp[n - 2]);
			}
			else {
				printf("L");
				DP(n - 2, 1, r - 1LL);
			}
		}
		else if (r == 1) {
			printf("U");
			if (l > 1 + dp[n - 2]) DP(n - 1, l - 1LL - dp[n - 2], 1);
			else DP(n - 2, l - 1LL, 1);
		}
		else {
			if (l > 1 + dp[n - 2]) DP(n - 1, l - 1LL - dp[n - 2], 1);
			else DP(n - 2, l - 1LL, 1);
			printf("U");
			if (r > 1 + dp[n - 2]) {
				printf("R");
				DP(n - 1, 1, r - 1LL - dp[n - 2]);
			}
			else {
				printf("L");
				DP(n - 2, 1, r - 1LL);
			}
		}
	}
}

int main(void) {
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= 50; ++i) dp[i] = dp[i - 2] + dp[i - 1] + 1;
	//for (int i = 2; i <= 50; ++i) printf("%lld\n", dp[i]);
	scanf("%d %lld %lld", &n, &l, &r);
	
	DP(n, l, r);
	puts("");
	return 0;
}
