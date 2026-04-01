#include <stdio.h>

int main(void) {
	int n, s, e;
	scanf("%d", &n);
	printf("? 1\n");
	fflush(stdout);
	scanf("%d", &s);
	printf("? %d\n", n);
	fflush(stdout);
	scanf("%d", &e);
	if (s == e) printf("! 0\n");
	else if (s > e) printf("! -1\n");
	else printf("! 1\n");
	return 0;
}
