#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#pragma warning(disable:4996)

int n, m;
char prime_index[10000001];
int prime[6000000], idx = 0;

void eratos() {
	int sq = (int)sqrt(10000001);
	prime_index[0] = prime_index[1] = 1;
	for (int i = 2; i <= sq; i++) {
		if (!prime_index[i]) {
			for (int j = i * i; j < 10000001; j += i) {
				prime_index[j] = 1;
			}
		}
	}
    /*
    prime[idx++] = 2;
	for (int i = 3; i < 100000001; i += 2) {
		if (!prime_index[i]) {
			prime[idx++] = i;
		}
	}
	*/
}

int main() {
	scanf("%d %d", &n, &m);
	eratos();
	m = m > 10000000 ? 10000000 : m;
	for (int i = n; i <= m; ++i) {
		if (prime_index[i]) continue;
		char s[35];
		int l, r, c = 0;
		sprintf(s, "%d", i);
		l = 0;
		r = strlen(s) - 1;
		while (l < r) {
			if (s[l] != s[r]) {
				c = 1;
				break;
			}
			++l;
			--r;
		}
		if (!c)
			printf("%d\n", i);
	}
	printf("-1\n");
	return 0;
}