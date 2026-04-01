#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int main(void) {
	int a, b, c, x, y, m;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	if (a + b < c * 2) printf("%d\n", a * x + b * y);
	else {
		m = min(x, y);
		printf("%d\n", c * 2 * m + (x - m) * min(a, c * 2) + (y - m) * min(b, c * 2));
	}
	return 0;
}
