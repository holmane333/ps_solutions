#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (!(a % b)) {
		puts("0");
		return 0;
	}
	
	for (int i = 0; i < c; ++i) {
		a %= b;
		a *= 10;
	}
	
	printf("%d\n", a / b);
	return 0;
}
