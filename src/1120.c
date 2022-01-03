#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int stick[7] = { 64,32,16,8,4,2,1 };

int main() {
	char ch1[50], ch2[50];
	scanf("%s %s", ch1, ch2);
	int len1 = strlen(ch1);
	int len2 = strlen(ch2);
	int min=50, result;
	for (int i = 0; i < len2 - len1+1; i++) {
		result = 0;
		for (int j = i; j < len1+i; j++) {
			if (ch1[j - i] != ch2[j]) result++;
		}
		if (result < min) min = result;
	}
	printf("%d", min);
	return 0;
}