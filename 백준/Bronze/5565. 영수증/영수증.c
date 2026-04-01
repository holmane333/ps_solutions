#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int data[10];

int main() {
	int total;
	scanf("%d", &total);
	for (int i = 0; i < 9; i++) {
		scanf("%d", &data[i]);
		total -= data[i];
	}
	printf("%d\n", total);
	return 0;
}