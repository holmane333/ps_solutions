#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int main() {
	int n, m;
	do {
		scanf("%d %d", &n, &m);
		if ((n == 0) && (m == 0)) break;
		if (n % m == 0) printf("multiple\n");
		else if (m % n == 0) printf("factor\n");
		else printf("neither\n");
	}while(1);


	return 0;
}