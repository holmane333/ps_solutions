#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
	int a[2000010] = {0, }, v[2000010] = {0, };
	int n, t;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		a[t] = 1;
	}
	if (a[0] == 0) {
		puts("0");
		return 0;
	}
	for (int i = 1; i <= 2000003; ++i) {
		if (!a[i]) continue;
		for (int j = i; j <= 2000003 / i; ++j) {
			if (!a[j]) continue;
			v[i * j] = 1;
		}
	}
	for (int i = 1; i <= 2000003; ++i) {
		if (!v[i]) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
