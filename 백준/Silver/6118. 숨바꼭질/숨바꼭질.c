#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n, m, check[20020], len[20020];
int* map[20020];

void bfs() {
	int q[20020], ft = 0, rr = 0;
	q[ft++] = 1;
	while (ft != rr) {
		int x = q[rr++];
		for (int i = 0; i < len[x]; ++i) {
			if (!check[map[x][i]]) {
				check[map[x][i]] = check[x] + 1;
				q[ft++] = map[x][i];
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; ++i) map[i] = (int*)malloc(sizeof(int));
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a] = (int*)realloc(map[a], sizeof(int) * (++len[a]));
		map[b] = (int*)realloc(map[b], sizeof(int) * (++len[b]));
		map[a][len[a] - 1] = b;
		map[b][len[b] - 1] = a;
	}
	check[1] = 1;
	bfs();
	int res = 0, idx = 1e9, cnt = 0;
	for (int i = 0; i <= n; ++i) {
		if (check[i] == res) ++cnt;
		else if (check[i] > res) {
			res = check[i];
			idx = i;
			cnt = 1;
		}
	}
	printf("%d %d %d\n", idx, res - 1, cnt);
	return 0;
}
