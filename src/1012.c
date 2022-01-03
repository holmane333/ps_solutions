#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

int pos[51][51];
int col, row;

void set(int i, int j) {
	pos[i][j] = 0;
	if (j + 1 <= row && pos[i][j + 1] == 1) {
		set(i, j + 1);
	}
	if (i + 1 <= col && pos[i + 1][j] == 1) {
		set(i + 1, j);
	}
	if (j - 1 >= 0 && pos[i][j - 1] == 1) {
		set(i, j - 1);
	}
	if (i - 1 >= 0 && pos[i - 1][j] == 1) {
		set(i - 1, j);
	}
}

int main() {
	int count, a, b, testcase, n;
	scanf("%d", &testcase);
	for (int tc = 0; tc < testcase; tc++) {
		count = 0;
		scanf("%d %d %d", &col, &row, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			pos[a][b] = 1;
		}
		for (int i = 0; i <= col; i++) {
			for (int j = 0; j <= row; j++) {
				if (pos[i][j] == 1) {
					set(i, j);
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}