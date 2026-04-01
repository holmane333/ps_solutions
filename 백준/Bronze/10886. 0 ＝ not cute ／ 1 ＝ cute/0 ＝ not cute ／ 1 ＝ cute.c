#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int data[101], result[2] = { 0, };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
		result[data[i]]++;
	}
	printf("%s\n", result[0]>result[1]?"Junhee is not cute!":"Junhee is cute!");
	return 0;
}