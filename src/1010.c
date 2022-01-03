#include <stdio.h>

#pragma warning(disable:4996)



long long int fac(long long int n, long long int m) {

	if (n <= 1) return 1;

	if (m == 0) return 1;

	return n * fac(n - 1, m - 1);

}

long long int cal(long long int a, long long int b) {

	if (a == 0) return 1;
	return fac(a, b) / fac(b, b);

}



int main() {

	long long int i, testcase, a, b;

	scanf("%lld", &testcase);

	for (i = 0; i < testcase; i++) {

		scanf("%lld %lld", &a, &b);

		
		if ((b - a) < a) printf("%lld\n", cal(b, b - a));
		else printf("%lld\n", cal(b,a));

	}



	return 0;

}