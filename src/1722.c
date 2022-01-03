#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

long long int fact[21];
int check[21];

int main() {
	int n;
	scanf("%d", &n);
	int c, ary[21], res[21] = { 0, };
	long long int data, ans = 1;
	scanf("%d", &c);
	fact[0] = 1;
	for (int i = 1; i < 21; i++) {
		fact[i] = fact[i - 1] * i;
	}
	switch (c)
	{
	case 1:
		scanf("%lld", &data);
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!check[j]) {
					if (fact[n - i - 1] < data) data -= fact[n - i - 1];
					else {
						res[i] = j;
						check[j] = 1;
						break;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			printf("%d ", res[i]);
		}
		break;
	case 2:
		for (int i = 0; i < n; i++) {
			scanf("%d", &ary[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < ary[i]; j++) {
				if (!check[j]) ans += fact[n - i - 1];
			}
			check[ary[i]] = 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
