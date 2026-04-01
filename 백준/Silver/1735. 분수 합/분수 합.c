#include <stdio.h>
#pragma warning(disable:4996)

int gcd(a, b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int main(void) {
	int a1, b1, a2, b2, g;
	scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
	g = gcd(b1, b2);
	a1 *= b2 / g;
	a2 *= b1 / g;
	
	a1 += a2;
	b1 = b1 * b2 / g;
	g = gcd(a1, b1);
	printf("%d %d\n", a1 / g, b1 / g);
	return 0;
}
