#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (b >= c) puts("-1");
	else printf("%d\n", a / (c - b) + 1);
	
	return 0;
}