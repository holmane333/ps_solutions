#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

char a[30];
int n, idx[200010], ino[200010], preo[200010];

void loop(int inl, int inr, int prel, int prer) {
	if (inl > inr || prel > prer) return;
	
	int root = preo[prel];
	//printf("%d %d %d %d %d\n", inl, inr, prel, prer, root);
	loop(inl, idx[root] - 1, prel + 1, prel + (idx[root] - inl));
	loop(idx[root] + 1, inr, prel + (idx[root] - inl) + 1, prer);
	printf("%c", (char)(root - 1) + 'A');
	//printf("%d ", root);
}

int main(void) {
	while (1) {
		if (scanf("%s", a) == EOF) break;
		for (int i = 0; i < strlen(a); ++i) preo[i] = (int)(a[i] - 'A') + 1;
		scanf("%s", a);
		for (int i = 0; i < strlen(a); ++i) ino[i] = (int)(a[i] - 'A') + 1;
		for (int i = 0; i < strlen(a); ++i) idx[ino[i]] = i;
		loop(0, strlen(a) - 1, 0, strlen(a) - 1);
		puts("");
	}
	return 0;
}
