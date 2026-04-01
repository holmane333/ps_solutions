#include <stdio.h>
#pragma warning(disable:4996)

int main(void) {
	int n, f;
	scanf("%d %d", &n, &f);
	n = n / 100 * 100;
	for (int i = 0; i < 100; ++i) {
		if (!(n % f)) {
			printf("%02d\n", i);
			return 0;
		}
		++n;
	}
	
	return 0;
}
