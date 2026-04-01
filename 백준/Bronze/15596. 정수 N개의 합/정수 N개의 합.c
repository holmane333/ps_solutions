#include <stdio.h>

long long int sum(int* a, int n) {
	long long int result = 0;
	for (int i = 0; i < n; i++) {
		result += a[i];
	}
	return result;
}
