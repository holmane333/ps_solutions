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
void quick_sort(struct Node* data, int start, int end) {
	if (start >= end) {
		return;
	}
	int pivot = start;
	int i = pivot + 1;
	int j = end; struct Node temp;
	while (i <= j) {
		while (i <= end && data[i].value <= data[pivot].value) {
			i++;
		}
		while (j > start && data[j].value >= data[pivot].value) {
			j--;
		}
		if (i > j) {
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end);
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
	quick_sort(node, 0, M - 1);
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	long long ans = 0;
	long long MX = 0;
	for (int i = 0; i < M; i++) {
		if (unionFind(node[i].first, node[i].second) == 0) {
			if (MX < node[i].value)
				MX = node[i].value;
			ans += node[i].value;
		}
	}
	free(node);
	free(nd);
	printf("%lld\n", ans);
	return 0;

}