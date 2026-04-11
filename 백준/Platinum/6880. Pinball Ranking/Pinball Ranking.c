#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#pragma warning(disable:4996)

typedef struct node{
	long long data;
	int idx;
}node;

int n;
node ary[100002];
int comp[100002];
long long seg_tree[400008];

int compare(const void *a, const void *b) {
	long long num1 = ((node *)a)->data;
	long long num2 = ((node *)b)->data;
	
	if (num1 < num2) return -1;
	if (num1 > num2) return 1;
	
	int idx1 = ((node *)a)->idx;
	int idx2 = ((node *)b)->idx;
	if (idx1 < idx2) return -1;
	if (idx1 > idx2) return 1;
	
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
	
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &(ary[i].data));
		ary[i].idx = i;
	}
	// assert(!(ary[1].data == 100 && ary[2].data == 200 && ary[3].data == 150 && ary[4].data == 170 && ary[5].data == 50));
	
	qsort(ary + 1, n, sizeof(node), compare);
	
	int k = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1 || ary[i].data != ary[i-1].data) {
			k++;
		}
		comp[ary[i].idx] = k;
	}
	
	long long res = 0;
	
	for (int i = 1; i <= n; i++) {
		int cur = comp[i];
		long long cnt = sum(1, 1, k, cur + 1, k);
		
		res += (cnt + 1);
		update(1, 1, k, cur, 1LL);
	}
	
	printf("%.2f\n", (double)res / n);
	
	return 0;
}