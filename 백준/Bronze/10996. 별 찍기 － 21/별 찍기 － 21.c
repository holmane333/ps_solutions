#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)


int main() {
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("*");
	}
	else {
		for (int i = 0; i < n*2; i++) {
			for (int j = 0; j < n; j++) {
				if ((i + j) % 2) printf(" ");
				else printf("*");
			}


			puts("");
		}
	}
	return 0;
}