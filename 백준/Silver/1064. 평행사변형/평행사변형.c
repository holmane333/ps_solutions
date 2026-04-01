#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) > (y) ? (y) : (x))

double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
	return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
}

double distance(double x1, double y1, double x2, double y2) {
	return (double)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) * 2.0f;
}

int main(void) {
	double x1, y1, x2, y2, x3, y3;
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
	if (!ccw(x1, y1, x2, y2, x3, y3)) puts("-1");
	else {
	double dis1, dis2, dis3;
		dis1 = distance(x1, y1, x2, y2);
		dis2 = distance(x1, y1, x3, y3);
		dis3 = distance(x2, y2, x3, y3);
		
		printf("%.16lf\n", max(max(dis1, dis2), dis3) - min(min(dis1, dis2), dis3));
	}
	return 0;
}
