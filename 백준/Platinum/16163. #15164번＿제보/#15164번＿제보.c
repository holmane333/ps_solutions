#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

void manachers(char s[], long long ary[], int n) {
	long long r = 0LL, p = 0LL;
	for (int i = 1; i <= n; i++) {
		if (i <= r)
			ary[i] = min(ary[2 * p - i], r - i);
		else
			ary[i] = 0LL;

		while (i - ary[i] - 1 > 0 && i + ary[i] + 1 <= n && s[i - ary[i] - 1] == s[i + ary[i] + 1])
			ary[i] += 1LL;
		
		if (r < i + ary[i]) {
			r = i + ary[i];
			p = i;
		}
	}
}

int main(void) {
	int n, m, n2 = 1;
	char s1[3000010], s2[6000010];
	long long ary2[6000010] = { 0, };
	scanf("%s", s1 + 1);
	n = strlen(s1 + 1);
	for (int i = 1; i <= n; ++i) {
		s2[n2++] = '#';
		s2[n2++] = s1[i];
	}
	s2[n2] = '#';
	s2[n2 + 1] = '\0';
	manachers(s2, ary2, n2);
	
	long long res = 0LL;
	for (int i = 1; i <= n2; ++i) {
		res += ary2[i] / 2LL;
		if (!(i % 2)) res += 1LL;
	}
	//for (int i = 1; i <= n2; ++i) printf("%lld ", ary2[i]); puts("");
	printf("%lld\n", res);
	
	return 0;
}