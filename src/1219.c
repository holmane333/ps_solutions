#include <stdio.h>
#include <limits.h>

int n, m, s, e;
int ary[110][110][3], len[110], money[110], visit[110];
long long d[110];

void dfs(int now) {
	visit[now] = 1;
	for (int i = 0; i < len[now]; ++i) {
		if (visit[ary[now][i][0]] == 0) {
			dfs(ary[now][i][0]);
		}
	}
}

int main() {
	scanf("%d %d %d %d", &n, &s, &e, &m);
	for (int i = 0; i < n; ++i) {
		d[i] = INT_MIN;
	}
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ary[a][len[a]][0] = b;
		ary[a][len[a]++][1] = -c;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &money[i]);
	}
	
	dfs(s);
	if (!visit[e]) {
		printf("gg\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < len[i]; ++j) {
			ary[i][j][1] += money[ary[i][j][0]];
		}
	}
	d[s] = money[s];
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < len[j]; ++k) {
				int next = ary[j][k][0];
				long long cost = ary[j][k][1];
				if (d[j] == INT_MAX) d[next] = INT_MAX;
				else if (d[j] != INT_MIN && d[next] < d[j] + cost) {
					d[next] = d[j] + cost;
					if (i >= n) d[next] = INT_MAX;
				}
			}
		}
	}

	if (d[e] == INT_MAX) printf("Gee\n");
	else printf("%lld\n", d[e]);
	return 0;
}
