#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int n, m, q, mat[3010][3010], a, b, c, d, dir[3010], d1, d2;
	for (int i = 0; i < 3010; ++i) dir[i] = i;
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &mat[i][j]);
		}
	}
	
	for (int i = 0; i < q; ++i) {
		scanf("%d", &a);
		if (!a) {
			scanf("%d %d %d", &b, &c, &d);
			mat[dir[b]][c] = d;
		}
		else {
			scanf("%d %d", &b, &c);
			d1 = dir[b];
			d2 = dir[c];
			dir[b] = d2;
			dir[c] = d1;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d", mat[dir[i]][j]);
			if (j != m) printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
