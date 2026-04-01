#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int cmp(const void* a, const void* b) {
	return *(char*)a - *(char*)b;
}

int main(void) {
	char s[60], t;
	scanf("%s", s);
	int n = strlen(s), a[30] = {0, };
	qsort(s, n, sizeof(char), cmp);
	
	for (int i = 0; i < n; ++i) {
		++a[(int)(s[i] - 'a')];
	}
	for (int i = 0; i < 30; ++i) {
		if (a[i] > (n + 1) / 2) {
			puts("-1");
			return 0;
		}
	}
	
	for (int i = (n + 1) / 2; i < n; ++i) {
		if (s[i] == s[n - i - 1]) {
			for (int j = i + 1; j < n; ++j) {
				if (s[i] != s[j]) {
					swap(s[i], s[j], t);
					break;
				}
			}
		}
	}
	
	printf("%s\n", s);
	return 0;
}
