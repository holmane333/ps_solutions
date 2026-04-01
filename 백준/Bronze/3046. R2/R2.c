#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", b * 2 - a);
	return 0;
}