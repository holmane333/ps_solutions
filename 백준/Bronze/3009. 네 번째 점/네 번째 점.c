#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int main() {
	int x1,x2,x3,y1,y2,y3;
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	scanf("%d %d", &x3, &y3);
	printf("%d %d\n", (x1 == x2 ? x3 : x1 == x3 ? x2 : x1), (y1 == y2 ? y3 : y1 == y3 ? y2 : y1));

	return 0;
}