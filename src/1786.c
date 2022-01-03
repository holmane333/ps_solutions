#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define MAX_TERMS 1001
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

char str[1000001], pat[1000001];
int data[1000001], cnt, rest[2000000], lth1, lth2;

void failure() {
	int j = 0;
	for (int i = 0; i < lth1; i++) {
		while (j > 0 && str[i] != pat[j]) j = data[j - 1];
		if (str[i] == pat[j]) {
			if (j == lth2 - 1) {
				rest[cnt++] = i - lth2 + 2;
				j = data[j];
			}
			else j++;
		}
	}
}

int main()
{
	gets(str);
	gets(pat);

	lth1 = strlen(str);
	lth2 = strlen(pat);

	int j = 0;
	for (int i = 1; i < lth2; i++) {
		while (j > 0 && pat[i] != pat[j]) j = data[j - 1];
		if (pat[i] == pat[j]) data[i] = ++j;
	}
	failure();
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", rest[i]);
	}
	
	return 0;
}
