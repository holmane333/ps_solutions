#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

int data[31] = { 0, };


int main() {
	int n;
	for (int i = 0; i < 28; i++) {
		scanf("%d", &n);
		data[n] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (!(data[i])) printf("%d\n", i);
	}
	
	return 0;
}