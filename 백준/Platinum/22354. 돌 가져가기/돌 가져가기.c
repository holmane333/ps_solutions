#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n;
char str[300030];
int ary[300030], ary2[300030];

int cmp(const void* num1, const void* num2) {
	return *(int*)num2 - *(int*)num1;
}

int main(void) {
	scanf("%d", &n);
	scanf("%s", str + 1);
	int len = 0;
	char prev = str[1];
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &ary[i]);
		if (str[i] == prev) {
			ary2[len] = max(ary2[len], ary[i]);
		}
		else {
			prev = str[i];
			ary2[++len] = ary[i];
		}
	}
	++len;
	//for (int i = 0; i < len; ++i) printf("%d ", ary2[i]); puts("");
	long long res = 0LL;
	if (len <= 2) {
		printf("%lld\n", res);
		return 0;
	}
	qsort(ary2 + 1, len - 2, sizeof(int), cmp);
	for (int i = 1; i <= (len - 2) / 2 + (len - 2) % 2; ++i) {
		res += (long long)ary2[i];
	}
	//for (int i = 0; i < len; ++i) printf("%d ", ary2[i]); puts("");
	printf("%lld\n", res);
	return 0;
}
