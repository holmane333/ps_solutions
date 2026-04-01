#include <stdio.h>
#pragma warning(disable:4996)

int n, m, a, temp, cnt = 1;
int main(void) {
	scanf("%d %d", &n, &m);
	temp = m;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		if (a > temp) {
			++cnt;
			temp = m - a;
		}
		else temp -= a;
	}
	if (!n) cnt = 0;
	printf("%d\n", cnt);
	return 0;
}
