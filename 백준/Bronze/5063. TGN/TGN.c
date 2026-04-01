#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)


int main() {
	int n;
	scanf("%d", &n);
	int a, b, c;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (b - c > a) printf("advertise\n");
		else if (b - c == a) printf("does not matter\n");
		else printf("do not advertise\n");
	}
	
	return 0;
}