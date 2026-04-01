#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

int len[200010], res[200010], init[200010], last[200010];
int* ary[200010];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &len[i]);
		ary[i] = malloc(sizeof(int) * len[i] + 1);
		for (int j = 0; j < len[i]; ++j) {
			scanf("%d", &ary[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i) scanf("%d", &res[i]);
	for (int i = 1; i <= n; ++i) last[i] = res[i];
	for (int i = m; i >= 1; --i) {
		int c = 0;
		for (int j = 0; j < len[i]; ++j) {
			if (res[ary[i][j]] == 0) {
				c = 1;
				break;
			}
		}
		if (c == 1) {
			for (int j = 0; j < len[i]; ++j) {
				res[ary[i][j]] = 0;
			}
		}
	}
	for (int i = 1; i <= n; ++i) init[i] = res[i];
	for (int i = 1; i <= m; ++i) {
		int c = 0;
		for (int j = 0; j < len[i]; ++j) {
			if (res[ary[i][j]]) {
				c = 1;
				break;
			}
		}
		if (c == 1) {
			for (int j = 0; j < len[i]; ++j) {
				res[ary[i][j]] = 1;
			}
		}
	}
	
	int c = 0;
	for (int i = 1; i <= n; ++i) {
		if (res[i] != last[i]) {
			c = 1;
			break;
		}
	}
	if (c == 1) printf("NO\n");
	else {
		printf("YES\n");
		for (int i = 1; i <= n; ++i) printf("%d ", init[i]); puts("");
	}
	return 0;
}
