#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int l, a, b, c, d;
	scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
	while (1) {
		if ((a <= 0) && (b <= 0)) break;
		a -= c;
		b -= d;
		l--;
	}
	printf("%d\n", l);
}