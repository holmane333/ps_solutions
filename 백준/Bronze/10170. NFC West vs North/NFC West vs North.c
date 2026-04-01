#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	printf("NFC West       W   L  T\n");
	printf("-----------------------\n");
	printf("Seattle        13  3  0\n");
	printf("San Francisco  12  4  0\n");
	printf("Arizona        10  6  0\n");
	printf("St. Louis      7   9  0\n");
	printf("\n");
	printf("NFC North      W   L  T\n");
	printf("-----------------------\n");
	printf("Green Bay      8   7  1\n");
	printf("Chicago        8   8  0\n");
	printf("Detroit        7   9  0\n");
	printf("Minnesota      5  10  1\n");

	return 0;
}