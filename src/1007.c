#include <stdio.h>
#include <memory.h>
#include <limits.h>
#include <math.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int n;
int map[30][4], check[30];
long long res = LLONG_MAX;

void dfs(int idx, int cnt) {
	if (idx > n || cnt > n / 2) return;
	if (cnt == n / 2) {
		int x = 0, y = 0;
		for (int i = 1; i <= n; ++i) {
			if (check[i]) {
				x += map[i][1];
				y += map[i][2];
			}
			else {
				x -= map[i][1];
				y -= map[i][2];
			}
		}
		//printf("%d %d\n", x, y);
		long long a = ((long long)x * x) + ((long long)y * y);
		//printf("%lld\n", a);
		res = min(res, a);
		return;
	}
	dfs(idx + 1, cnt);
	check[idx] = 1;
	dfs(idx + 1, cnt + 1);
	check[idx] = 0;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		memset(map, 0, sizeof(map));
		scanf("%d", &n);
		res = LLONG_MAX;
		for (int i = 1; i <= n; ++i) {
			scanf("%d %d", &map[i][1], &map[i][2]);
		}
		dfs(1, 0);
		printf("%lf\n", sqrt(res));
	}
	return 0;
}