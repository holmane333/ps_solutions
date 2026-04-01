#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int n, k, count = 0, c = 0;
int res[11], idx = 0;

void dfs(int cnt) {
	if (cnt > n) return;
	if (cnt == n) {
		count++;
		if (count == k) {
			for (int i = 0; i < idx; i++) {
				printf("%d", res[i]);
				if (i != idx - 1 && idx > 1) printf("+");
			}
			puts("");
			c = 1;
		}
		return;
	}
	for (int i = 1; i < 4; i++) {
		if (c == 1) return;
		res[idx++] = i;
		dfs(cnt + i);
		idx--;
	}
}

int main() {
	int dp[11];
	scanf("%d %d", &n, &k);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	dfs(0);
	if (!c) printf("-1\n");
	
	return 0;
}
