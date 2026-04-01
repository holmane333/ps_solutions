#include <stdio.h>
#pragma warning(disable:4996)

int n, m;
long long ary[2030][1030], fen_tree[2050][2050];

void update(int i, int j, long long diff) {
	while (i <= n) {
		int sj = j;
		while (sj <= n) {
			fen_tree[i][sj] += diff;
			sj += (sj & -sj);
		}
		i += (i & -i);
	}
}

long long sum(int i, int j) {
	long long res = 0;
	while (i > 0) {
		int sj = j;
		while (sj > 0) {
			res += fen_tree[i][sj];
			sj -= (sj & -sj);
		}
		i -= (i & -i);
	}
	return res;
}

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &ary[i][j]);
			update(i, j, ary[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		if (a == 0) {
			int b, c;
			long long d;
			scanf("%d %d %lld", &b, &c, &d);
			long long diff = d - ary[b][c];
			ary[b][c] = d;
			update(b, c, diff);
		}
		else {
			int b, c, d, e;
			scanf("%d %d %d %d", &b, &c, &d, &e);
			//printf("%lld %lld %lld %lld\n", sum(d, e), sum(d, c - 1), sum(b - 1, e), sum(b - 1, c - 1));0
			printf("%lld\n", sum(d, e) - sum(d, c - 1) - sum(b - 1, e) + sum(b - 1, c - 1));
		}
	}
	
	
	return 0;
}
