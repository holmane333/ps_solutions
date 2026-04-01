#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	long long int a = 1, b = 1, k;
	int n;
	scanf("%d", &n);
	if (n <= 2) printf("%d", 1);
	else {
		for (int i = 0; i < n-3; i++) {
			k = a;
			a += b;
			b = k;
		}
		printf("%lld", a + b);
	}


	return 0;
}
