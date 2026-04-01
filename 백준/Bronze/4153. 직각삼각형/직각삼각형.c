#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int main() {
	int x, y, z, a, b, c;
	do {
		scanf("%d %d %d", &x, &y, &z);
		if ((x == 0) && (y == 0) && (z == 0)) break;
		x *= x;
		y *= y;
		z *= z;
		if ((x + y == z) || (x + z == y) || (y + z == x)) puts("right");
		else puts("wrong");

	} while (1);
}