#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	char ary[51][51];
	for (int i = 0; i < n; i++) {
		scanf("%s", ary[i]);
	}
	int res = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 1; k < min(n, m); k++) {
				if (i + k < n && j + k < m && ary[i + k][j] == ary[i][j] && ary[i][j + k] == ary[i][j] && ary[i + k][j + k] == ary[i][j]) res = max(res, k + 1);
			}
		}
	}
	printf("%d\n", res * res);
	
	
	return 0;
}
