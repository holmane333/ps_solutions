#include <stdio.h>
#pragma warning(disable:4996)

int n, ary[500001];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	int stack[500001][2], top = 0;
	long long res = 0LL;
	for (int i = 0; i < n; i++) {
		while (top != 0 && stack[top - 1][0] < ary[i]) {
			res += stack[--top][1];
		}
		if (top == 0) {
			stack[top][0] = ary[i];
			stack[top++][1] = 1;
		}
		else {
			if (stack[top - 1][0] == ary[i]) {
				res += stack[top - 1][1];
				stack[top - 1][1]++;
				if (top != 1) res++;
			}
			else {
				stack[top][0] = ary[i];
				stack[top++][1] = 1;
				res++;
			}
		}
	}
	printf("%lld\n", res);
	return 0;
}
