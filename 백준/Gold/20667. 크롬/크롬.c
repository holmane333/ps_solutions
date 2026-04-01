#pragma warning(disable:4996)
#include <stdio.h>
#include <memory.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int n, cm, mm, c[110], m[110], p[110], dp[110][1010][510];

int DP(int nowi, int nowc, int nowp) {
	if (nowi >= n) {
		if (nowc >= cm) return 0;
		return -1e9;
	}
	if (nowc >= 1001) nowc = 1000;
	if (dp[nowi][nowc][nowp] != -1) return dp[nowi][nowc][nowp];
	
	dp[nowi][nowc][nowp] = -1e9;
	if (nowp - p[nowi] >= 0) dp[nowi][nowc][nowp] = max(dp[nowi][nowc][nowp], DP(nowi + 1, nowc + c[nowi], nowp - p[nowi]) + m[nowi]);
	dp[nowi][nowc][nowp] = max(dp[nowi][nowc][nowp], DP(nowi + 1, nowc, nowp));
	
	return dp[nowi][nowc][nowp];
}

int main(void) {
	scanf("%d %d %d", &n, &cm, &mm);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d %d", &c[i], &m[i], &p[i]);
	}
	memset(dp, -1, sizeof(dp));
	int t;
	for (int i = 0; i < 501; ++i) {
		t = DP(0, 0, i);
		if (t >= mm) {
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
