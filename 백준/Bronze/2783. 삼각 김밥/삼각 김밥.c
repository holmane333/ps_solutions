#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	double min = 10000000.0, data = 0.0;
	int g1, g2, n;
	scanf("%d %d", &g1, &g2);
	data = (1000.0 / g2) * g1;
	if (min > data) min = data;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &g1, &g2);
		data = (1000.0 / g2) * g1;
		if (min > data) min = data;
	}
	printf("%.2lf\n", min);
	return 0;
}