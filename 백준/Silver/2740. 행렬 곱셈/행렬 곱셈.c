#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int mat1[200][200], mat2[200][200], res[200][200];
int cnt1, cnt2, cnt3;

void matz(int n, int m, int l) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++) {
			for (int k = 0; k < m; k++) {
				res[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	return;
}


int main()
{
	int n, m, l;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mat1[i][j]);
		}
	}
	scanf("%d %d", &m, &l);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < l; j++) {
			scanf("%d", &mat2[i][j]);
		}
	}
	matz(n, m, l);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++) {
			printf("%d ", res[i][j]);
		}
		puts("");
	}
	return 0;
}