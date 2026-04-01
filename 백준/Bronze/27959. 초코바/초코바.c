#pragma warning(disable:4996)
#include <stdio.h>

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n * 100 >= m) puts("Yes");
	else puts("No");
	
	
	return 0;
}
