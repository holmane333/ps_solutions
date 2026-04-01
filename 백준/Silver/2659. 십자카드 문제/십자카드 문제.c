#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int rotate(int n) {
	int minv = n;
	for (int i = 0; i < 3; ++i) {
		n = n % 1000 * 10 + n / 1000;
		minv = min(minv, n);
	}
	return minv;
}

int main() {
	int a, b, c, d, t;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	t = rotate(a * 1000 + b * 100 + c * 10 + d);
	
	int cnt = 1;
	for (int i = 1111; i < t; ++i) {
		if (rotate(i) == i) ++cnt;
	}
	
	printf("%d\n", cnt);
	return 0;
}