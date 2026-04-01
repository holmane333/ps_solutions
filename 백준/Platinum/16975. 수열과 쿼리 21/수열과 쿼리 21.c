#include <stdio.h>
#pragma warning(disable:4996)

int n, m;
long long ary2[1000002], ary[1000002], fen_tree[1000002];

void update(int i, long long diff) {
	while (i <= n) {
		fen_tree[i] += diff;
		i += (i & -i);
	}
}

long long sum(int i) {
	long long res = 0;
	while (i > 0) {
		res += fen_tree[i];
		i -= (i & -i);
	}
	return res;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &ary2[i]);
		ary[i] = ary2[i] - ary2[i - 1];
		update(i, ary[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b, c;
			long long diff;
			scanf("%d %d %lld", &b, &c, &diff);
			update(b, diff);
			update(c + 1, -diff);
		}
		else {
			int b;
			scanf("%d", &b);
			printf("%lld\n", sum(b));
		}
	}
	
	
	return 0;
}
