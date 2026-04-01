#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int mat1[129][129];
int cnt1, cnt2;

int clrpaper(int n, int x, int y) {
	if (n == 1) {
		if (mat1[x][y]) cnt2++;
		else cnt1++;
		return 1;
	}
	int t = mat1[x][y];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat1[x + i][y + j] != t) {
				return clrpaper(n / 2, x, y) + clrpaper(n / 2, x + n / 2, y) + clrpaper(n / 2, x, y + n / 2) + clrpaper(n / 2, x + n / 2, y + n / 2);
			}
		}
	}
	if (t) cnt2++;
	else cnt1++;
	return 1;
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
	printf("%d\n%d\n", cnt1, cnt2);


	return 0;
}