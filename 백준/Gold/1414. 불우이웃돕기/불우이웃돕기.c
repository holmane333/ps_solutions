#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

struct Node {
	int first;
	int second;
	long long value;
}Nd;

struct Node *node;
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
	int N, M = 0;
	long long ans = 0;
	char a[60];
	scanf("%d", &N);
	node = (struct Node*)malloc(sizeof(struct Node) * (N * N + 1));
	for (int i = 1; i <= N; i++) {
		scanf("%s", &a);
		for (int j = 1; j <= N; ++j) {
			if (a[j - 1] != '0') {
				node[M].first = i;
				node[M].second = j;
				if (a[j - 1] >= 'a' && a[j - 1] <= 'z')
					node[M].value = (int)(a[j - 1] - 'a') + 1;
				else
					node[M].value = (int)(a[j - 1] - 'A') + 27;
				ans += node[M].value;
				++M;
			}
		}
	}
	quick_sort(node, 0, M - 1);
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (unionFind(node[i].first, node[i].second) == 0) {
			ans -= node[i].value;
			++cnt;
		}
	}
	free(node);
	if (cnt == N - 1)
		printf("%lld\n", ans);
	else
		printf("-1\n");
	return 0;

}