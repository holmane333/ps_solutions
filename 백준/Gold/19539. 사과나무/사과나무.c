#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {

	int n, ary[100001], cnt_2 = 0;
	long long int res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
		res += ary[i];
		cnt_2 += ary[i] / 2;
	}

	if (!(res % 3LL) && cnt_2 >= res / 3LL) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	return 0;
}