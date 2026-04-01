#pragma warning(disable:4996)
#include <stdio.h>
#define ll long long

int n;
char a[30];

int dfs(i, t) {
	if (t < 0) return 0;
	if (i == n && t == 0) {
		printf("%s\n", a);
		return 1;
	}
	if (a[i] == 'G') {
		a[i] = '(';
		if (dfs(i + 1, t + 1)) return 1;
		a[i] = ')';
		if (dfs(i + 1, t - 1)) return 1;
	}
	else {
		if (a[i] == '(') {
			if (dfs(i + 1, t + 1)) return 1;
		}
		else {
			if (dfs(i + 1, t - 1)) return 1;
		}
	}
	return 0;
}

int main(void) {
	scanf("%d", &n);
	scanf("%s", a);
	if (!dfs(0, 0)) printf("-1\n");
	
	return 0;
}
