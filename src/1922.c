#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int first;
	int second;
	long long value;
}Nd;

struct Node *node;
struct Node *nd;
int parent[100001];

int cmp(const void* a, const void* b) {
    if ((*(struct Node*)a).value == (*(struct Node*)b).value) return 0;
    return (*(struct Node*)a).value > (*(struct Node*)b).value;
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
	int N, M; scanf("%d %d", &N, &M);
	node = (struct Node*)malloc(sizeof(struct Node) * M);
	nd = (struct Node*)malloc(sizeof(struct Node) * M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %lld", &node[i].first, &node[i].second, &node[i].value);
	}
	qsort(node, M, sizeof(struct Node), cmp);
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	long long ans = 0;
	long long MX = 0;
    int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (unionFind(node[i].first, node[i].second) == 0) {
			if (MX < node[i].value)
				MX = node[i].value;
			ans += node[i].value;
            ++cnt;
           // if (cnt == N - 1) break;
		}
	}
	free(node);
	free(nd);
	printf("%lld\n", ans);
	return 0;

}