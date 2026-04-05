#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int main(void) {
	double x, y, c;
	scanf("%lf %lf %lf", &x, &y, &c);
	
	double l = 0.0, r = min(x, y), m, res = 0.0, h1, h2, temp;
	while (r - l > 0.000001) {
		m = (l + r) / 2.0;
		h1 = sqrt(x * x - m * m);
		h2 = sqrt(y * y - m * m);
		temp = (h1 * h2) / (h1 + h2);
		//printf("%lf %lf %lf %lf\n", l, r, m, temp);
		if (temp >= c) {
			res = m;
			l = m;
		}
		else r = m;
	}
	
	printf("%.3lf\n", res);
	return 0;
}
