#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main(void) {
	int l, cnt = 0;
	char a[1010], c[5] = {'U', 'C', 'P', 'C'};
	gets(a);
	l = strlen(a);
	for (int i = 0; i < l; ++i) {
		if (cnt == 4) break;
		if (a[i] == c[cnt]) ++cnt;
	}
	if (cnt == 4) printf("I love UCPC\n");
	else printf("I hate UCPC\n");
	return 0;
}
