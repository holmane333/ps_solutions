#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main() {
	int n;
	scanf("%d", &n);
	char list[51][51],result[51];
	for (int i = 0; i < n; i++) {
		scanf("%s", &list[i]);
	}
	int size = strlen(list[0]);
	int c;
	char t;
	for (int i = 0; i < size; i++) {
		c = 0;
		t = list[0][i];
		for (int j = 0; j < n; j++) {
			if (t != list[j][i]) {
				c = 1;
				break;
			}
		}
		if (c == 0) result[i] = t;
		else result[i] = '?';
	}
	for (int i = 0; i < size; i++) printf("%c", result[i]);

	return 0;
}