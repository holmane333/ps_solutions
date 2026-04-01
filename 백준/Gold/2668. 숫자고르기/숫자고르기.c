#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n, ary[101];
int res[101], check[101];
int dfs(int s, int f) {
	check[f] = 1;
	if (ary[f] == s) return 1;
	else if (check[ary[f]]) return 0;
	else return dfs(s, ary[f]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ary[i]);
	}
	int cnt = 0, mark = -1;
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		res[i] = dfs(i, i);
		if (res[i]) cnt++;
	}
	
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++) {
		if (res[i]) printf("%d\n", i);
	}

	return 0;
}