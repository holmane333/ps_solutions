#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#include <memory.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

int res, cnt, v[60], vv[60], n;
char a[60][60];

void dfs(int idx, int d) {
	if (d == 2) return;
	for (int i = 1; i <= n; ++i) {
		if (a[idx][i] == 'Y' && !v[i]) {
			if (!vv[i]) ++cnt;
			v[i] = 1;
			vv[i] = 1;
			dfs(i, d + 1);
			v[i] = 0;
		}
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", a[i] + 1);
	}
	
	for (int i = 1; i <= n; ++i) {
		memset(v, 0, sizeof(v));
		memset(vv, 0, sizeof(vv));
		cnt = 0;
		v[i] = 1;
		vv[i] = 1;
		dfs(i, 0);
		//printf("%d %d %d\n", i, res, cnt);
		res = max(res, cnt);
	}
	
	printf("%d\n", res);
	return 0;
}
