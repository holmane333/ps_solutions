#include <stdio.h>
#include <limits.h>

int n, m, s;
long long ary[510][510][3];
int len[510], visit[510];
long long d[510];

void dfs(int now) {
	visit[now] = 1;
	for (int i = 0; i < len[now]; ++i) {
		if (visit[ary[now][i][0]] == 0) {
			dfs(ary[now][i][0]);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; ++i) {
		d[i] = INT_MAX;
	}
	s = 1;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		ary[a][len[a]][0] = b;
		ary[a][len[a]++][1] = c;
	}
	dfs(s);
	d[s] = 0;
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < len[j]; ++k) {
				int next = ary[j][k][0];
				long long cost = ary[j][k][1];
				if (d[j] == INT_MIN) d[next] = INT_MIN;
				else if (d[j] != INT_MAX && d[next] > d[j] + cost) {
					//printf("%d %d : %lld + %lld, %lld\n", j, next, cost, d[j], d[next]);
					d[next] = d[j] + cost;
					if (i >= n) d[next] = INT_MIN;
				}
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (d[i] == INT_MIN) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (!visit[i]) printf("-1\n");
		else printf("%lld\n", d[i]);
	}
	return 0;
}
