#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int mat1[10001][3], dp[10001], dpa[10001], dpb[10001], dpc[10001];
int n, m;


int cmp2(int x, int y) {
	return x + y > m ? 2 : 1;
}

void z2() {
	if (mat1[1][1] + mat1[1][2] <= m) {
		dpa[1] = dpb[1] = dpc[1] = 1;
	}
	else {
		dpa[1] = 2;
		dpb[1] = dpc[1] = 1;
	}
	
	for (int i = 2; i <= n; ++i) {
		dpa[i] = dpa[i - 1] + 2;
		dpb[i] = dpc[i] = dpa[i - 1] + 1;
		
		if (mat1[i][1] + mat1[i - 1][1] <= m) {
			dpb[i] = min(dpb[i], dpc[i - 1] + 1);
		}
		if (mat1[i][2] + mat1[i - 1][2] <= m) {
			dpc[i] = min(dpc[i], dpb[i - 1] + 1);
		}
		dpa[i] = min(min(dpa[i], dpb[i] + 1), dpc[i] + 1);
		if (mat1[i][1] + mat1[i][2] <= m) {
			dpa[i] = min(dpa[i], dpa[i - 1] + 1);
		}
		if (mat1[i][1] + mat1[i - 1][1] <= m && mat1[i][2] + mat1[i - 1][2] <= m) {
			dpa[i] = min(dpa[i], dpa[i - 2] + 2);
		}
	}
}

int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int tt = 0; tt < testcase; tt++) {
		memset(mat1, 0, sizeof(mat1));
		memset(dpa, 0, sizeof(dpa));
		memset(dpb, 0, sizeof(dpb));
		memset(dpc, 0, sizeof(dpc));
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &mat1[j][i]);
			}
		}
		if (n == 1) {
			printf("%d\n", cmp2(mat1[1][1], mat1[1][2]));
		}
		else {
			int count = INT_MAX;
			z2();
			count = min(count, dpa[n]);
			//printf("%d\n", count);
			if (mat1[1][1] + mat1[n][1] <= m) {
				int t1 = mat1[1][1], t2 = mat1[n][1];
				mat1[1][1] = m;
				mat1[n][1] = m;
				z2();
				count = min(count, dpc[n]);
				//printf("%d\n", dpc[n] + 1);
				mat1[1][1] = t1;
				mat1[n][1] = t2;
			}
			if (mat1[1][2] + mat1[n][2] <= m) {
				int t1 = mat1[1][2], t2 = mat1[n][2];
				mat1[1][2] = m;
				mat1[n][2] = m;
				z2();
				count = min(count, dpb[n]);
				//printf("%d\n", dpb[n] + 1);
				mat1[1][2] = t1;
				mat1[n][2] = t2;
				
			}
			if (mat1[1][1] + mat1[n][1] <= m && mat1[1][2] + mat1[n][2] <= m) {
				int t1 = mat1[1][1], t2 = mat1[n][1];
				int t3 = mat1[1][2], t4 = mat1[n][2];
				mat1[1][1] = m;
				mat1[n][1] = m;
				mat1[1][2] = m;
				mat1[n][2] = m;
				z2();
				count = min(count, dpa[n - 1]);
				//printf("%d\n", dpa[n - 1] + 1);
				mat1[1][1] = t1;
				mat1[n][1] = t2;
				mat1[1][2] = t3;
				mat1[n][2] = t4;
			}
			printf("%d\n", count);
		}
	}
	return 0;
}