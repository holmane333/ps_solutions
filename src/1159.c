#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int alpha[26] = { 0, };

int main() {
	int n,k,c;
	char list[151][30];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &list[i]);
	}
	for (int i = 0; i < n; i++) {
		k = (int)list[i][0] - 97;
		alpha[k]++;
	}
	c = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] >= 5) {
			printf("%c", (char)(97 + i));
			c = 1;
		}
	}
	if (c == 0) printf("PREDAJA");


	return 0;
}