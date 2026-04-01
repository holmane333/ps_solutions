#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int data[101];

int main() {
	int n, m, total = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &data[i]);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if ((total < data[i] + data[j] + data[k]) && (m >= data[i] + data[j] + data[k])) total = data[i] + data[j] + data[k];
			}
		}
	}
	printf("%d\n", total);
	return 0;
}