#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <string.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int dp[60], n, l, wl[60], v[30];
char pat[60];
char w[60][60];

int check(int idx, int i) {
	memset(v, 0, sizeof(v));
	for (int j = 0; j < wl[i]; ++j) {
		++v[(int)(pat[idx + j] - 'a')];
		--v[(int)(w[i][j] - 'a')];
	}
	for (int i = 0; i < 30; ++i) {
		if (v[i]) return 0;
	}
	return 1;
}

int count(int idx, int i) {
	//printf("%d %d\n", idx, i);
	int cnt = 0;
	for (int j = 0; j < wl[i]; ++j) {
		cnt += (pat[idx + j] != w[i][j]);
	}
	return cnt;
}

int DP(int idx) {
	if (idx == l) return 0;
	if (idx > l) return 1e9;
	if (dp[idx] != -1) return dp[idx];
	
	dp[idx] = 1e9;
	int t;
	for (int i = 0; i < n; ++i) {
		if (idx + wl[i] > l) continue;
		if (check(idx, i)) {
			t = count(idx, i);
			dp[idx] = min(dp[idx], DP(idx + wl[i]) + t);
		}
	}
	return dp[idx];
}

int main(void) {
	scanf("%s", pat);
	l = strlen(pat);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", w[i]);
		wl[i] = strlen(w[i]);
	}
	
	memset(dp, -1, sizeof(dp));
	if (DP(0) == 1e9) puts("-1");
	else printf("%d\n", dp[0]);
	return 0;
}
