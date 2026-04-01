#include <stdio.h>

int main(void) {
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	printf("%d %d\n", (b*f - c*e) / (b*d - a*e), (a*f - d*c) / (a*e - b*d));
	return 0;
}
