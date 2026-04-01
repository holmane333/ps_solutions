#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

void manachers(int s[], int ary[], int n) {
	int r = 0, p = 0;
	for (int i = 1; i <= n; i++) {
		if (i <= r)
			ary[i] = min(ary[2 * p - i], r - i);
		else
			ary[i] = 0;

		while (i - ary[i] - 1 > 0 && i + ary[i] + 1 <= n && s[i - ary[i] - 1] == s[i + ary[i] + 1])
			ary[i]++;

		if (r < i + ary[i]) {
			r = i + ary[i];
			p = i;
		}
	}
}

int main(void) {
	int n, m, n2 = 1;
	scanf("%d", &n);
	int s1[2000010], s2[3000010], ary1[2000010], ary2[3000010];
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &s1[i]);		
		s2[n2++] = 0;
		s2[n2++] = s1[i];
	}
	s2[n2] = 0;
	manachers(s2, ary2, n2);

	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int idx = (b + a) / 2 * 2 + (b + a) % 2;
		printf("%d\n", ary2[idx] / 2 >= (b - a) / 2 + (b - a) % 2 ? 1 : 0);
	}

	//for (int i = 1; i <= n2; ++i) printf("%d ", s2[i]); puts("");
	//for (int i = 1; i <= n2; ++i) printf("%d ", ary2[i]); puts("");
	return 0;
}