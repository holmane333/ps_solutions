#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#pragma warning (disable:4996)


int main() {
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	int res1, res2;
	res1 = a * e;
	res2 = c > e ? b : b + d * (e - c);
	printf("%d", res1 > res2 ? res2 : res1);

	return 0;
}