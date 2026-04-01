#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#pragma warning(disable:4996)
#define MOD 1000000007

typedef struct trie* TR;
typedef struct trie{
	int cnt[30];
	int end;
	TR next[30];
}trie;

long long dp[2000000];

void insert(TR tree, char str[100], int idx) {
	if (idx == strlen(str)) {
		tree->end = 1;
		return;
	}
	tree->cnt[(int)str[idx] - 97]++;
	if (tree->next[(int)str[idx] - 97] == NULL) {
		TR new1 = (TR)malloc(sizeof(trie));
		for (int i = 0; i < 30; ++i) new1->cnt[i] = 0;
		new1->end = 0;
		for (int i = 0; i < 26; i++) new1->next[i] = NULL;
		tree->next[(int)str[idx] - 97] = new1;
	}
	
	insert(tree->next[(int)str[idx] - 97], str, idx + 1);
}
/*
int find(TR tree, char f[], int idx) {
	if (idx >= strlen(f)) return 0;
	if (tree->next[(int)f[idx] - 97] == NULL) return 0;
	if (tree->cnt == 1 && tree->end == 0) return find(tree->next[(int)f[idx] - 97], f, idx + 1);
	return find(tree->next[(int)f[idx] - 97], f, idx + 1) + 1;
}*/

void tree_free(TR tree) {
	if (tree == NULL) return;
	for (int i = 0; i < 26; i++) {
		if (tree->next[i] != NULL) tree_free(tree->next[i]);
	}
	free(tree);
}

long long DP(TR tree, char f[], int idx) {
	if (idx >= strlen(f)) return 1LL;
	if (dp[idx] != -1) return dp[idx];
	dp[idx] = 0;
	int next_num = idx;
	TR now_tree = tree;
	while(1) {
		if (next_num >= strlen(f)) break;
		if (now_tree->cnt[(int)f[next_num] - 97] == 0) break;
		if (now_tree->next[(int)f[next_num] - 97] == NULL) break;
		dp[idx] = (dp[idx] + (long long)(now_tree->cnt[(int)f[next_num] - 97]) * DP(tree, f, next_num + 1)) % MOD;
		//printf("%d %lld %lld %lld\n", idx, dp[idx], (long long)(now_tree->cnt[(int)f[next_num] - 97]), DP(tree, f, next_num + 1));
		now_tree = now_tree->next[(int)f[next_num] - 97];
		++next_num;
	}
	
	return dp[idx];
}

int main(void) {
	int n;
	char str[310], word[200010];
	scanf("%d", &n);
	TR tree = (TR)malloc(sizeof(trie));
	for (int i = 0; i < 30; ++i) tree->cnt[i] = 0;
	tree->end = 0;
	for (int i = 0; i < 26; i++) {
		tree->next[i] = NULL;
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		insert(tree, str, 0);
	}
	scanf("%s", word);
	memset(dp, 0, sizeof(dp));
	int str_len = strlen(word);
	dp[0] = 1;
	for (int i = 0; i < str_len; ++i) {
		TR now_tree = tree;
		for (int j = i; j < str_len; ++j) {
		    int nxt = (int)word[j] - 97;
            if (now_tree->next[nxt] == NULL) break;
            dp[j + 1] = (dp[j + 1] + dp[i] * now_tree->cnt[nxt]) % MOD;
            now_tree = now_tree->next[nxt];
        }
	}
	printf("%lld\n", dp[str_len]);
	tree_free(tree);
	return 0;
}
