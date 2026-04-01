#include <stdio.h>
#pragma warning(disable:4996)

int n, m;
int fen_tree[1000002];

void update(int i, int diff) {
	while (i <= 200000) {
		fen_tree[i] += diff;
		i += (i & -i);
	}
}

int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += fen_tree[i];
		i -= (i & -i);
	}
	return res;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int q1, q2;
		q1 = sum(a);
		q2 = sum(b);
		
		update(a, -q1); update(a + 1, q1);
		update(b, -q2); update(b + 1, q2);
		
		update(a + 1, 1); update(b, -1);
		printf("%d\n", q1 + q2);
	}
	
	
	return 0;
}
