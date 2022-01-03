#include <stdio.h>
#pragma warning(disable:4996)

typedef struct node{
	long long data;
	int idx;
}node;

int n, m, k;
node ary[1000002];
long long seg_tree[2097154];

int compare(const void *a, const void *b) {
    int num1 = (*(node *)a).data;   
    int num2 = (*(node *)b).data;
    if (num1 < num2) return -1;  
    if (num1 > num2) return 1;  
    return 0;
}

void update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	seg_tree[node] = seg_tree[node] + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

long long sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0LL;
	if (left <= start && end <= right) return seg_tree[node];
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void) {
	scanf("%d", &n);
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &(ary[i].data));
		ary[i].idx = i;
	}
	qsort(ary + 1, n, sizeof(node), compare);
	for (int i = 1; i <= n; i++){
		res += sum(1, 1, n, ary[i].idx + 1, n);
		update(1, 1, n, ary[i].idx, 1LL);
	}
	printf("%lld\n", res);
	return 0;
}
