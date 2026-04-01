#include <stdio.h>
#pragma warning(disable:4996)
#define ll long long

int n;
ll t[40];

int main(void) {
	t[0] = 1;
	for (int i = 1; i < 36; ++i) {
		for (int j = 0; j < i; ++j) {
			t[i] += t[j] * t[i - j - 1];
		}
	}
	
	scanf("%d", &n);
	printf("%lld\n", t[n]);
	
	return 0;
}
