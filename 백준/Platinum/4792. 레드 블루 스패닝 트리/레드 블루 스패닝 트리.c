#include <stdio.h>

int parent[1001];

int getParent(int a) {
	if (a == parent[a]) return a;
	return parent[a] = getParent(parent[a]);
}

int unionFind(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	
	if (a != b) {
		if (a > b) parent[a] = b;
		else parent[b] = a;
		return 1;
	}
	return 0;
}

int main(void) {
	int n, m, k;
	int ary1[1000001][3], l1 = 0, ary2[1000001][3], l2 = 0;
	while (1) {
		scanf("%d %d %d", &n, &m, &k);
		if (n == 0 && m == 0 && k == 0) break;
		l1 = 0;
		l2 = 0;
		for (int i = 0; i < m; ++i) {
			int a, b;
			char c[4];
			scanf("%s %d %d", c, &a, &b);
			if (c[0] == 'B') {
				ary1[l1][0] = a;
				ary1[l1++][1] = b;
			}
			else {
				ary2[l2][0] = a;
				ary2[l2++][1] = b;
			}
		}
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < 1001; ++i) parent[i] = i;
		for (int i = 0; i < l1; ++i) {
			if (unionFind(ary1[i][0], ary1[i][1])) ++cnt1;
		}
		for (int i = 0; i < l2; ++i) {
			unionFind(ary2[i][0], ary2[i][1]);
		}
		for (int i = 0; i < 1001; ++i) parent[i] = i;
		for (int i = 0; i < l2; ++i) {
			unionFind(ary2[i][0], ary2[i][1]);
		}
		for (int i = 0; i < l1; ++i) {
			if (unionFind(ary1[i][0], ary1[i][1])) ++cnt2;
		}
		//printf("%d %d\n", cnt1, cnt2);
		if (cnt2 <= k && k <= cnt1) printf("1\n");
		else printf("0\n");
	}
	
	return 0;
}
