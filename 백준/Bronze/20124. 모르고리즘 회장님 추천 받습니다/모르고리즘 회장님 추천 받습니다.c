#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <limits.h>
#pragma warning(disable:4996)

int main() {
	int n;
	int data, max = INT_MIN;
	char name[12], max_name[12];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d", name, &data);
		if (max < data) {
			max = data;
			strcpy(max_name, name);
		}
		else if (max == data) {
			if (strcmp(max_name, name) > 0) strcpy(max_name, name);
		}
	}
	printf("%s\n", max_name);

	return 0;
}