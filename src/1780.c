#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int mat1[5000][5000];
int cnt1, cnt2, cnt3;

void clrpaper(int n, int x, int y) {
	if (n == 1) {
		if (mat1[x][y] == 1) cnt3++;
		else if (!mat1[x][y]) cnt2++;
		else cnt1++;
		return;
	}
	int t = mat1[x][y];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat1[x + i][y + j] != t) {
				clrpaper(n / 3, x, y);
				clrpaper(n / 3, x, y + n / 3);
				clrpaper(n / 3, x, y + 2 * n / 3);
				clrpaper(n / 3, x + n / 3, y);
				clrpaper(n / 3, x + n / 3, y + n / 3);
				clrpaper(n / 3, x + n / 3, y + 2 * n / 3);
				clrpaper(n / 3, x + 2 * n / 3, y);
				clrpaper(n / 3, x + 2 * n / 3, y + n / 3);
				clrpaper(n / 3, x + 2 * n / 3, y + 2 * n / 3);
				return;
			}
		}
	}
	if (t == 1) cnt3++;
	else if (!t) cnt2++;
	else cnt1++;
	return;
}


int main()
 {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &mat1[i][j]);
		}
	}
	clrpaper(n, 0, 0);
	printf("%d\n%d\n%d\n", cnt1, cnt2, cnt3);

	return 0;
}