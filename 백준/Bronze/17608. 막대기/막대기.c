#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int n, a[100010], cnt = 0, m = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] > m) {
			m = a[i];
			++cnt;
		}
	}
	
	printf("%d\n", cnt);
	return 0;
}
