#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

char data[100001];
char op[100001];
int main() {
	int c, cnt;
	for (;;) {
		cnt = 0;
		c = 0;
		for (int i = 0; i < 100001; i++) {
			op[i] = '\0';
		}
		gets(data);
		if (strlen(data) == 1 && data[0] == '.') break;
		for (int i = 0; c == 0 && i < strlen(data); i++) {
			if (data[i] == '[' || data[i] == '(') {
				op[cnt++] = data[i];
			}
			else if (data[i] == ']') {
				if (op[cnt - 1] == '[') op[--cnt] = '\0';
				else c = 1;
			}
			else if (data[i] == ')') {
				if (op[cnt - 1] == '(') op[--cnt] = '\0';
				else c = 1;
			}
		}
		if (c == 0 && cnt == 0) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}