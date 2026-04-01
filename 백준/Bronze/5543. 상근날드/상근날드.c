#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int data[5];

int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%d", &data[i]);
	}
	int min1 = 2001, min2 = 2001, total;
	for (int i = 0; i < 3; i++) {
		if (min1 > data[i]) min1 = data[i];
	}
	for (int i = 3; i < 5; i++) {
		if (min2 > data[i]) min2 = data[i];
	}
	total = min1 + min2 - 50;
	printf("%d\n", total);
	return 0;
}