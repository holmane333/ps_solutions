#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define ll long long
#define swap(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define max(x, y) ((x) > (y) ? (x) : (y))

int main(void) {
	char s[3000020];
	int a[2000010] = {0, };
	scanf("%s", s);
	int l = 0, r = strlen(s) - 1, res = 0, cntk = 0, cntr = 0;
	while (l <= r) {
		//printf("%d %d\n", l, r);
		if (l == r) {
			if (s[l] == 'R') ++cntr;
			a[cntk] = cntr;
			break;
		}
		if (s[l] == s[r] && s[l] == 'K') {
			a[cntk] = cntr;
			cntr = 0;
			++cntk;
			++l;
			--r;
		}
		else if (s[l] == 'R' && s[r] == 'R') {
			++cntr;
			++cntr;
			++l;
			--r;
		}
		else if (s[l] == 'R') {
			++cntr;
			++l;
		}
		else {
			++cntr;
			--r;
		}
	}
	a[cntk] = cntr;
	for (int i = 2000000; i >= 0; --i) {
		a[i - 1] += a[i];
	}
	for (int i = 0; i <= 2000000; ++i) {
		if (a[i]) res = max(res, a[i] + i * 2);
	}
	//for (int i = 0; i < 5; ++i) printf("%d\n", a[i]);
	printf("%d\n", res);
	return 0;
}
