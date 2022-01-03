#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	char str[7];
	scanf("%s", str);
	int res = 0;
	for (int i = 0; i < strlen(str); i++) {
		res *= 16;
		if ((int)str[i] >= 65 && (int)str[i] <= 70) res += (int)str[i] - 55;
		else res += (int)str[i] - 48;
	}
	printf("%d\n", res);


	return 0;
}