#include <stdio.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))

int l, w, h, n, p[22], cnt[22], res, c;

void box(int x, int y, int z, int idx) {
	int t = min(min(x, y), z);
	if (!t) return;
	
	for (int i = idx; i >= 0; --i) {
		//printf("%d %d %d: %d %d %d %d\n", x, y, z, i, cnt[i], p[i], t);
		if (!cnt[i] || p[i] > t) continue;
		++res;
		--cnt[i];
		box(x - p[i], p[i], p[i], i);
		box(x, y - p[i], p[i], i);
		box(x, y, z - p[i], i);
		return;
	}
	c = 1;
}

int main(void) {
	int a, b;
	scanf("%d %d %d", &l, &w, &h);
	scanf("%d", &n);
	p[0] = 1;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &a, &b);
		cnt[a] = b;
		p[i + 1] = p[i] << 1;
	}
	
	box(l, w, h, n - 1);
	if (!c) printf("%d\n", res);
	else printf("-1\n");
	
	return 0;
}
