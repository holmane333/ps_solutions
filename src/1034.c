#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#pragma warning(disable:4996)
#define swap(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

int main() {
	int n, m, data;
	long long int ary[51];
	char inp;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		ary[i] = 0;
		getchar();
		for (int j = m-1; j >= 0; j--) {
			scanf("%c", &inp);
			if (inp == '1') ary[i] = ary[i] | ((long long int)1 << j);
		}
	}
	scanf("%d", &data);
	int max = 0, cnt_0, max_cmp;
	long long int res;
	for (int i = 0; i < n; i++) {
		res = ary[i];
		cnt_0 = 0;
		max_cmp = 0;
		for (int j = 0; j < m; j++) {
			if (!(res % 2)) cnt_0++;
			res >>= 1;
		}
		for (int j = 0; j < n; j++) {
			if (ary[i] == ary[j]) max_cmp++;
		}
		if (data >= cnt_0 && data % 2 == cnt_0 % 2 && max < max_cmp) max = max_cmp;
	}
	printf("%d\n", max);



	return 0;
}