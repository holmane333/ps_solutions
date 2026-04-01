#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int main(void) {
	double x, y, d, t;
	scanf("%lf %lf %lf %lf", &x, &y, &d, &t);
	double dis = sqrt(x * x + y * y);
	double res = dis;
	int cnt = (int)(dis / d);
	dis -= (double)cnt * d;
	
	if (cnt) res = min(min(res, (double)cnt * t + dis), (double)(cnt + 1) * t);
	else res = min(min(res, t + d - dis), 2.0 * t);
	
	printf("%.20lf\n", res);
	return 0;
}
