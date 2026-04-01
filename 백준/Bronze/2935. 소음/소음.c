#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main()
{
	char str1[101], str2[101], op;
	int len1, len2, max;
	scanf("%s\n%c\n%s", str1, &op, str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	max = len1 > len2 ? len1 : len2;
	switch (op) {
	case '+':
		for (int i = 0; i < max; i++) {
			if (max - i == len1 && max - i == len2) printf("2");
			else if (max - i == len1 || max - i == len2) printf("1");
			else printf("0");
		}
		break;
	case '*':
		printf("1");
		for (int i = 0; i < len1 + len2 - 2; i++) printf("0");
		
		break;
	}

	
	return 0;
}