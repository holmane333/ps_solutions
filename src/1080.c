#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

int mat1[51][51], mat2[51][51];
int count = 0;

void rix(int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat1[i][j] != mat2[i][j]) {
				for (int k = 0; k < 3; k++) {
					for (int l = 0; l < 3; l++) {
						mat1[i + k][j + l] = mat1[i + k][j + l] ? 0 : 1;
					}
				}
				count++;
			}
		}
	}
}

int main() {
	int n, m, c = 0;
	char k;
	scanf("%d %d", &n, &m);
	for (int a = 0; a < 2; a++) {
		for (int i = 0; i < n; i++) {
			getchar();
			for (int j = 0; j < m; j++) {
				scanf("%c", &k);
				if (a == 0)
					mat1[i][j] = (int)k - 48;
				else
					mat2[i][j] = (int)k - 48;
			}
		}
	}

	rix(n - 2, m - 2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat1[i][j] != mat2[i][j]) c = 1;
		}
	}
	printf("%d\n", c ? -1 : count);


	return 0;
}