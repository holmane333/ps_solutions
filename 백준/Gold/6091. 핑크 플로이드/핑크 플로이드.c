#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int first;
	int second;
	int value;
}Nd;

struct Node *node;
int parent[1100], len[1100], *mat[1100];

int cmp(const void* a, const void* b) {
    if ((*(struct Node*)a).value == (*(struct Node*)b).value) return 0;
    return (*(struct Node*)a).value > (*(struct Node*)b).value;
}

int cmp2(const void* num1, const void* num2) {
	return *(int*)num1 - *(int*)num2;
}

int getParent(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = getParent(parent[a]);
}
int unionFind(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a != b) {
		if (a < b)
			parent[b] = a;
		else parent[a] = b;
		return 0;
	}
	return 1;
}
int main() {
	int N; scanf("%d", &N);
	node = (struct Node*)malloc(sizeof(struct Node) * (N * (N - 1) / 2));
	for (int i = 1; i <= N; ++i) mat[i] = (int*)malloc(sizeof(int));
	int idx = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			node[idx].first = i;
			node[idx].second = j;
			scanf("%d", &node[idx].value);
			++idx;
		}
	}
	qsort(node, idx, sizeof(struct Node), cmp);
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < idx; i++) {
		if (unionFind(node[i].first, node[i].second) == 0) {
			mat[node[i].first] = (int*)realloc(mat[node[i].first], sizeof(int) * (++len[node[i].first]));
			mat[node[i].second] = (int*)realloc(mat[node[i].second], sizeof(int) * (++len[node[i].second]));
			mat[node[i].first][len[node[i].first] - 1] = node[i].second;
			mat[node[i].second][len[node[i].second] - 1] = node[i].first;
		}
	}
	
	for (int i = 1; i <= N; ++i) {
		printf("%d ", len[i]);
		qsort(mat[i], len[i], sizeof(int), cmp2);
		for (int j = 0; j < len[i]; ++j) {
			printf("%d ", mat[i][j]);
		}
		puts("");
	}
	
	return 0;

}