#include <stdio.h>
#pragma warning(disable:4996)

double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
	return x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2;
}

int main(void) {
	int n;
	scanf("%d", &n);
	double p[10010][2];
	for (int i = 0; i < n; ++i) {
		scanf("%lf %lf", &p[i][0], &p[i][1]);
		//printf("%lf %lf\n", p[i][0], p[i][1]);
	}
	double res = 0.0f;
	for (int i = 1; i < n - 1; ++i) {
		res += ccw(p[0][0], p[0][1], p[i][0], p[i][1], p[i + 1][0], p[i + 1][1]) / 2.0;
		//printf("%.1lf\n", res);
	}
	if (res < 0.0) res *= -1;
	printf("%.1lf\n", res);
	return 0;
}
