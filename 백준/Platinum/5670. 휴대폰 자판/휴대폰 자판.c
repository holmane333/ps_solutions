#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#pragma warning(disable:4996)

typedef struct trie* TR;
typedef struct trie{
	int cnt;
	int end;
	TR next[30];
}trie;


void insert(TR tree, char str[100], int idx) {
	if (idx == strlen(str)) {
		tree->end = 1;
		return;
	}
	if (tree->next[(int)str[idx] - 97] == NULL) {
		tree->cnt++;
		TR new1 = (TR)malloc(sizeof(trie));
		new1->cnt = 0;
		new1->end = 0;
		for (int i = 0; i < 26; i++) new1->next[i] = NULL;
		tree->next[(int)str[idx] - 97] = new1;
	}
	
	insert(tree->next[(int)str[idx] - 97], str, idx + 1);
}

int find(TR tree, char f[], int idx) {
	if (idx >= strlen(f)) return 0;
	if (tree->cnt == 1 && tree->end == 0) return find(tree->next[(int)f[idx] - 97], f, idx + 1);
	return find(tree->next[(int)f[idx] - 97], f, idx + 1) + 1;
}

void tree_free(TR tree) {
	if (tree == NULL) return;
	for (int i = 0; i < 26; i++) {
		if (tree->next[i] != NULL) tree_free(tree->next[i]);
	}
	free(tree);
}

int main(void) {
	int n;
	char str[100001][100], inp[101];
	while(1) {
		TR tree = (TR)malloc(sizeof(trie));
		tree->cnt = 0;
		tree->end = 0;
		for (int i = 0; i < 26; i++) {
			tree->next[i] = NULL;
		}
		if (scanf("%s", inp) == EOF) break;
		n = atoi(inp);
		for (int i = 0; i < n; i++) {
			scanf("%s", str[i]);
			insert(tree, str[i], 0);
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			res += find(tree->next[(int)str[i][0] - 97], str[i], 1) + 1;
		}
		printf("%.2f\n", (float)res / (float)n);
		tree_free(tree);
	}
	return 0;
}
