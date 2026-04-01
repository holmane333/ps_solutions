#include <stdio.h>
#pragma warning(disable:4996)

int n, a[21], s[2000010];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	
	int t = (1 << n), temp;
	for (int i = 1; i < t; ++i) {
		temp = 0;
		for (int b = 0; b < n; ++b) {
			if (i & (1 << b)) {
				temp += a[b];
			}
		}
		s[temp] = 1;
	}
	
	for (int i = 1; i <= 2000000; ++i) {
		if (!s[i]) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
