#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int n, w[30], res = 0;

void dfs(int i, int k) {
	if (i == n) {
		if (k == ((1 << 26) - 1)) ++res;
		return;
	}
	dfs(i + 1, k);
	dfs(i + 1, k | w[i]);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		char word[110];
		scanf("%s", word);
		int l = strlen(word), k = 0;
		for (int j = 0; j < l; ++j) {
			k |= (1 << ((int)word[j] - 97));
		}
		w[i] = k;
	}
	
	dfs(0, 0);
	printf("%d\n", res);
	return 0;
}
