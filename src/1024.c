#include <stdio.h>
#include <memory.h>
#pragma warning(disable:4996)

int main(void) {
	int n, l;
	scanf("%d %d", &n, &l);
	for (int i = l; i <= 100; i++) {
		int x = n - i * (i + 1) / 2;
		if (x % i == 0) {
			int temp = x / i + 1;
			if (temp >= 0) {
				for (int j = 0; j < i; j++) {
					printf("%d ", temp + j);
				}
				printf("\n");
				return 0;
			}
		}
	}
    printf("-1\n");
	return 0;
}
