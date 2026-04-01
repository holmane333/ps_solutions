#include <stdio.h>
#pragma warning(disable:4996)

int n, idx[200010], ino[200010], preo[200010];

void loop(int inl, int inr, int prel, int prer) {
	if (inl > inr || prel > prer) return;
	
	int root = preo[prer];
	printf("%d ", root);
	loop(inl, idx[root] - 1, prel, prel + (idx[root] - inl) - 1);
	loop(idx[root] + 1, inr, prel + (idx[root] - inl), prer - 1);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", &ino[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &preo[i]);
	for (int i = 0; i < n; ++i) idx[ino[i]] = i;
	loop(0, n - 1, 0, n - 1);
	puts("");
	return 0;
}
