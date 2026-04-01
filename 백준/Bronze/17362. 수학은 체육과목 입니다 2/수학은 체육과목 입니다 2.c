#include <stdio.h>
 
int main(void) {
	int n;
	scanf("%d", &n);
	--n;
	n %= 8;
	++n;
	if (n <= 5) printf("%d\n", n);
	else if (n == 6) printf("4\n");
	else if (n == 7) printf("3\n");
	else printf("2\n");
 
	return 0;
}
 