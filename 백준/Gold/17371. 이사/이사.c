#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int resx1, resy1, resx2, resy2, dis = 1e9;
int n;
int ary[2001][3];

int distance(int ax, int ay, int bx, int by) {
	return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}


int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &ary[i][0], &ary[i][1]);
	}
	for (int i = 0; i < n; ++i) {
		int Max = -1;
		int resxx1 = 0, resyy1 = 0, resxx2 = 0, resyy2 = 0;
		for (int j = 0; j < n; ++j) {
			int new1 = distance(ary[i][0], ary[i][1], ary[j][0], ary[j][1]);
			if (new1 > Max) {
				resxx1 = ary[i][0];
				resyy1 = ary[i][1];
				resxx2 = ary[j][0];
				resyy2 = ary[j][1];
				Max = new1;
			}
		}
		if (dis > Max) {
			resx1 = resxx1;
			resy1 = resyy1;
			resx2 = resxx2;
			resy2 = resyy2;
			dis = Max;
		}
	}
	printf("%d %d\n", resx1, resy1);
	return 0;
}
