#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	n /= 4;
	for (int i = 0; i < n; ++i) {
		printf("long ");
	}
	puts("int");
    return 0;
}
