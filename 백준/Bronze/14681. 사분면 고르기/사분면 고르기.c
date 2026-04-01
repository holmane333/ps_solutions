#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d\n%d", &n, &m);
	if (n > 0 && m > 0) printf("1");
	else if (n < 0 && m > 0) printf("2");
	else if (n > 0 && m < 0) printf("4");
	else printf("3");

	return 0;
}