#include <stdio.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int main() {
	int n;
	scanf("%d", &n);
	int x[7], xmax = -1, ymax = -1;
	for (int i = 0; i < 6; i += 2) {
		int temp;
		scanf("%d %d", &temp, &x[i]);
		scanf("%d %d", &temp, &x[i + 1]);
		xmax = max(xmax, x[i]);
		ymax = max(ymax, x[i + 1]);
	}
	x[6] = x[0];
	
	int res = xmax * ymax * -2;
	for (int i = 0; i < 6; ++i) {
		res += x[i] * x[i + 1];
	}
	
	printf("%d\n", res * n);
	return 0;
}
