#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int mat1[129][129];
int cnt1, cnt2;

void clrpaper(int n, int x, int y) {
	if (n == 1) {
		if (mat1[x][y]) printf("1");
		else printf("0");
		return;
	}
	int t = mat1[x][y];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat1[x + i][y + j] != t) {
				printf("(");
				clrpaper(n / 2, x, y);
				clrpaper(n / 2, x, y + n / 2);
				clrpaper(n / 2, x + n / 2, y);
				clrpaper(n / 2, x + n / 2, y + n / 2);
				printf(")");
				return;
			}
		}
	}
	if (t) printf("1");
	else printf("0");
	return;
}


int main()
 {
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%c", &mat1[i][j]);
			mat1[i][j] -= 48;
		}
		getchar();
	}
	clrpaper(n, 0, 0);


	return 0;
}