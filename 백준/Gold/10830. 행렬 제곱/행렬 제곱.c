#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int n;
int ary[6][6];
long long int k;

void multp(long long int b, int mat1[6][6], int res[6][6]) {
	
	if (b == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mat1[i][j] = ary[i][j] % 1000;
			}
		}
	}
	else if (b % 2 == 0) {
		multp(b / 2, mat1, res);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					mat1[i][j] += res[i][k] * res[k][j];
				}
				mat1[i][j] %= 1000;
			}
		}
	}
	else {
		multp(b - 1, mat1, res);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					mat1[i][j] += res[i][k] * ary[k][j];
				}
				mat1[i][j] %= 1000;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = mat1[i][j];
			mat1[i][j] = 0;
		}
	}
	if (b == k) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", res[i][j]);
			}
			puts("");
		}
	}
	return;
}

int main() {
	int mat1[6][6] = { 0, }, res[6][6] = { 0, };
	scanf("%d %lld", &n, &k);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &ary[i][j]);
		}
	}

	multp(k, mat1, res);
	

	return 0;
}
