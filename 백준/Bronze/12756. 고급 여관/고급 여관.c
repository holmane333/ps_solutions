#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int a, b, c, d, t1, t2;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	t1 = d / a + (d % a > 0);
	t2 = b / c + (b % c > 0);
	
	if (t1 > t2) puts("PLAYER B");
	else if (t1 < t2) puts("PLAYER A");
	else puts("DRAW");
	return 0;
}
