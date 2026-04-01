#include <stdio.h>
#pragma warning(disable:4996)

int n, c[60], v[60], ans;
char map[60][60];

void dfs(int x) {
	if (v[x]) {
		ans = 1;
		return;
	}
	if (c[x]) return;
	c[x] = 1;
	v[x] = 1;
	for (int i = 0; i < n; ++i) {
		if (map[x][i] == 'Y') dfs(i);
	}
	v[x] = 0;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%s", map[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] == 'Y' && map[j][i] == 'Y') {
				map[i][j] = 'N';
				map[j][i] = 'N';
			}
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (!c[i]) dfs(i);
	}
	
	if (ans) printf("NO\n");
	else printf("YES\n");
	return 0;
}
