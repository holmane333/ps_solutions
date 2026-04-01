#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t) = (x), (x) = (y), (y) = (t))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int ary[1001], check[1001];

void dfs(int n) {
	check[n] = 1;
	if (!check[ary[n]]) dfs(ary[n]);
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 0; t < tc; t++) {
		int n, cnt = 0;
		memset(ary, 0, sizeof(ary));
		memset(check, 0, sizeof(check));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &ary[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}
