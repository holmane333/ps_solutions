#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)

int data[100001];

int main() {
	int n, m, cnt = 0, sum = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		if (m == 0) {
			data[cnt--] = 0;
		}
		else {
			data[cnt++] = m;
		}
	}
	for (int i = 0; i < cnt; i++) {
		sum += data[i];
	}
	printf("%d\n", sum);
	return 0;
}