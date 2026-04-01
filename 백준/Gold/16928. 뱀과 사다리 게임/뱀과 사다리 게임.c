#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m, ary[200], cnt = 0, v[200];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n + m; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ary[a] = b;
	}
	int q[500010], ft = 0, rr = 0;
	q[rr++] = 1;
	q[rr++] = -1;

	int c = 0;
	while (ft != rr) {
		int x = q[ft++];
		if (x == -1) {
			if (c == 1) break;
			c = 1;
			q[rr++] = -1;
			++cnt;
			continue;
		}
		c = 0;
		int k = 0;
		for (int i = 1; i <= 6; ++i) {
			int cx = x + i;
			if (cx == 100) {
				k = 1;
				break;
			}
			if (cx > 100) continue;

			if (ary[cx]) cx = ary[cx];
			if (!v[cx]) {
				v[cx] = 1;
				q[rr++] = cx;
			}
		}
		if (k == 1) break;
	}

	printf("%d\n", cnt + 1);
	return 0;
}