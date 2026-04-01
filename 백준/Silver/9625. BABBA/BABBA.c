#include <stdio.h>
#pragma warning(disable:4996)

int k;

int main(void) {
	scanf("%d", &k);
	int a = 1, b = 0, c;
	
	while (k--) {
		c = a;
		a = b;
		b += c;
	}
	
	printf("%d %d\n", a, b);
	return 0;
}
