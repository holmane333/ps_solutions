#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	char str[20000];
	scanf("%s", str);
	int len = strlen(str);
	int a = 1, b = 1, n = 1;
	int i = 0;
	while (i < len) {
		if (i == 0) n = a;
		if (n >= 100) {
			int temp = ((int)str[i] - (int)'0') * 100 + ((int)str[i + 1] - (int)'0') * 10 + (int)str[i + 2] - (int)'0';
			if (temp == n) {
				i += 3;
				++n;
			}
			else {
				i = 0;
				++a;
			}
		}
		else if (n >= 10) {
			int temp = ((int)str[i] - (int)'0') * 10 + (int)str[i + 1] - (int)'0';
			if (temp == n) {
				i += 2;
				++n;
			}
			else {
				i = 0;
				++a;
			}
		}
		else {
			int temp = (int)str[i] - (int)'0';
			if (temp == n) {
				++i;
				++n;
			}
			else {
				i = 0;
				++a;
			}
		}
	}
	b = n - 1;
	printf("%d %d\n", a, b);

	return 0;
}
