#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <limits.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	char str[1001];
	scanf("%s", str);
	int len = (int)strlen(str), c = 0, i, count = len;
	for (i = 0; i <= len; i++) {
		c = 0;
		for (int j = i; j < i+(count>>1); j++) {
			if (str[j] != str[len - 1 - j + i]) {
				c = 1;
				break;
			}
		}
		count -= 1;
		if (c == 0) break;
	}
	printf("%d\n", len + i);
	return 0;
}
