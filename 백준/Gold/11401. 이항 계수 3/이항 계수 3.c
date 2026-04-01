#include <stdio.h>
#include <memory.h>
#include <string.h>
#define div (unsigned long long) 1000000007
#pragma warning(disable:4996)

unsigned long long factorial[4000003];

void Factorial(unsigned long long k) {
	for (int i = 0; i <= k; i++) {
		if (i) factorial[i] = (i * factorial[i - 1]) % div;
		else factorial[i] = 1;
	}
	return;
}

unsigned long long mod(unsigned long long n, unsigned long long k) {
	if (k == 1) return n;
	unsigned long long t = mod(n, k / 2);
	unsigned long long result = (t * t) % div;
	if (k % 2 == 1) result = (result * n) % div;
	return result;
}

int main() {
	int n, k;
	Factorial(4000002);
	scanf("%d %d", &n, &k);
	unsigned long long num1, num2;
	num1 = mod((factorial[k] * factorial[n - k]) % div, div - 2);
	num2 = ((factorial[n] * num1) % div);
	printf("%llu\n", num2);


	return 0;
}