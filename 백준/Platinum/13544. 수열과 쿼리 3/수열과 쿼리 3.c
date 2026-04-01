#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable:4996)

int n;
int len[2000010];
long long ary[200010];
long long* seg_tree[2000010];

int compare(const void* num1, const void* num2) {
	long long a = *(long long*)num1;
	long long b = *(long long*)num2;
	return a - b;
}

int upper_bound(long long *arr, int n, long long key){
    int start = 0;
    int end = n;
    int mid;
 
    while(end - start > 0) {
        mid = (start + end) / 2;
        if(arr[mid] <= key) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return end;
}

void update(int node, int start, int end, int idx, long long diff) {
	if (idx < start || idx > end) return;
	seg_tree[node] = realloc(seg_tree[node], sizeof(long long) * (++len[node]));
	seg_tree[node][len[node] - 1] = diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, diff);
	update(node * 2 + 1, mid + 1, end, idx, diff);
}

int sum(int node, int start, int end, int left, int right, long long key) {
	if (right < start || left > end) return 0;
	if (left <= start && end <= right) return len[node] - upper_bound(seg_tree[node], len[node], key);
	int mid = (start + end) / 2;
	int a = sum(node * 2, start, mid, left, right, key);
	int b = sum(node * 2 + 1, mid + 1, end, left, right, key);
	return a + b;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= 500000; ++i) {
		seg_tree[i] = malloc(sizeof(long long));
		len[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &ary[i]);
		update(1, 1, n, i, ary[i]);
	}
	for (int i = 1; i <= 500000; ++i) qsort(seg_tree[i], len[i], sizeof(long long), compare);
	int t;
	long long prev = 0;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		long long x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		x ^= prev;
		y ^= prev;
		z ^= prev;
		prev = (long long)sum(1, 1, n, x, y, z);
		printf("%lld\n", prev);
	}
	return 0;
}
