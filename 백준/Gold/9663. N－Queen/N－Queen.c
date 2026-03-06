#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

int flag_a[10000];
int flag_b[100000];
int flag_c[100000];
int pos[20];
int count = 0;
int n;

void set(int i) {
	for (int j = 1; j < n+1; j++) {
		if (flag_a[j] == 0 && flag_b[i + j] == 0 && flag_c[i - j + 7] == 0) {
			pos[i] = j;
			if (i == n) count++;
			else {
				flag_a[j] = 1;
				flag_b[i + j] = 1;
				flag_c[i - j + 7] = 1;
				set(i + 1);
				flag_a[j] = 0;
				flag_b[i + j] = 0;
				flag_c[i - j + 7] = 0;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	set(1);
	printf("%d", count);


	return 0;
}