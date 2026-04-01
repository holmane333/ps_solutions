#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	c -= a;
	if (c <= 0) puts("1");
	else printf("%d\n", 1 + c / (a - b) + (c % (a - b) ? 1 : 0));

	return 0;
}