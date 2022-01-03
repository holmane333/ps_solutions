#include <stdio.h>
#include <memory.h>
#include <string.h>
#pragma warning(disable:4996)
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, k, res;
char word[51][20];
int visit[27];

void dfs(int t, int cnt) {
	if (cnt == k) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			int size = strlen(word[i]);
			int check = 1;
			for (int j = 0; j < size; j++) {
				if (!visit[word[i][j] - 'a']) {
					check = 0;
					break;
				}
			}
			if (check == 1) count++; 
		}
		res = max(res, count);
	}
	else {
		for (int i = t; i < 26; i++) {
			if (!visit[i]) {
				visit[i] = 1;
				dfs(i, cnt + 1);
				visit[i] = 0;
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &k);
	char input[20];
	for (int i = 0; i < n; i++) {
		scanf("%s", input);
		strncpy(word[i], input + 4, strlen(input) - 8);
	}
	if (k < 5) printf("0\n");
	else if (k == 26) printf("%d\n", n);
	else {
		k -= 5;
		visit['a' - 'a'] = 1;
		visit['c' - 'a'] = 1;
		visit['i' - 'a'] = 1;
		visit['n' - 'a'] = 1;
		visit['t' - 'a'] = 1;
		dfs(0, 0);
		
		printf("%d\n", res);
	}
	return 0;
}
