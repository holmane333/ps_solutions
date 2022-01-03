#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
 
int main(void) {
	while(1) {
		char str[20];
		scanf("%s", str);
		if (str[0] == '0' && strlen(str) == 1) {
			return 0;
		}
		int len = strlen(str), c = 0;
		for (int i = 0; i < len / 2; i++) {
			if (str[i] != str[len - i - 1]) c = 1;
		}
		if (c == 0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}