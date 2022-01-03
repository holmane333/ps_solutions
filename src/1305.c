#include <stdio.h>
#pragma warning(disable:4996)
 
int n, pi[1000002];
char str[1000002];
 
int main(void) {
	scanf("%d", &n);
	scanf("%s", str);
	int j = 0;
	for (int i = 1; i < n; i++) {
		while (str[i] != str[j] && j > 0) j = pi[j - 1];
		if (str[i] == str[j]) pi[i] = ++j;
	}
	printf("%d\n", n - pi[n - 1]);
	return 0;
}
 