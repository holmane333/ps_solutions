#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m;
long long ary[320], dp[320][320][3];

int cmp(const void* num1, const void* num2) {
	return *(long long*)num1 - *(long long*)num2;
}

int lower_bound(int s, int e, long long key) {
	int start = s;
	int end = e - 1;
	int mid;
	while (end - start > 0) {
		mid = (start + end) / 2;
		if (ary[mid] < key) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
	return end;
}

long long DP(int l, int r, int f, int cnt) {
	if (!cnt) return 0LL;
	if (l > r) return INT_MAX;
	if (dp[l][r][f] != -1) return dp[l][r][f];
	dp[l][r][f] = INT_MAX;

	int idx = f ? l : r;
	
	if (l - 1 >= 1)
		dp[l][r][f] = min(dp[l][r][f], DP(l - 1, r, 1, cnt - 1) + cnt * (ary[idx] - ary[l - 1]));

	if (r + 1 <= n)
		dp[l][r][f] = min(dp[l][r][f], DP(l, r + 1, 0, cnt - 1) + cnt * (ary[r + 1] - ary[idx]));
	return dp[l][r][f];
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%lld", &ary[i]);
	long long res = 0LL;
	ary[++n] = 0;
	qsort(ary + 1, n, sizeof(long long), cmp);
	int idx = lower_bound(1, n + 1, 0LL);
	for (int i = 0; i <= n; ++i) {
		memset(dp, -1, sizeof(dp));
		res = max(res, i * m - DP(idx, idx, 0, i));
	}
	printf("%lld\n", res);
	return 0;
}
