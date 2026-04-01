#include <stdio.h>
#pragma warning(disable:4996)
#define mod 1000000007

typedef struct node{
	long long data, lazy, lazy2;
}node;

int n, m, k;
long long ary[1000002];
node seg_tree[2097154];

long long init(int node, int start, int end) {
	seg_tree[node].lazy2 = 1;
	if (start == end)
		return seg_tree[node].data = ary[start] % mod;
	else
		return seg_tree[node].data = (init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end)) % mod;
}

void rangeupdate(int node, int start, int end, int left, int right, long long diff, long long diff2) {
	if (seg_tree[node].lazy != 0 || seg_tree[node].lazy2 != 1) {
		seg_tree[node].data = seg_tree[node].data * seg_tree[node].lazy2 + seg_tree[node].lazy * (end - start + 1);
		seg_tree[node].data %= mod;
		if (start != end) {
			seg_tree[node * 2].lazy = seg_tree[node * 2].lazy * seg_tree[node].lazy2 + seg_tree[node].lazy;
			seg_tree[node * 2 + 1].lazy = seg_tree[node * 2 + 1].lazy * seg_tree[node].lazy2 + seg_tree[node].lazy;
			seg_tree[node * 2].lazy2 *= seg_tree[node].lazy2;
			seg_tree[node * 2 + 1].lazy2 *= seg_tree[node].lazy2;
			seg_tree[node * 2].lazy %= mod;
			seg_tree[node * 2 + 1].lazy %= mod;
			seg_tree[node * 2].lazy2 %= mod;
			seg_tree[node * 2 + 1].lazy2 %= mod;
		}
		seg_tree[node].lazy = 0;
		seg_tree[node].lazy2 = 1;
	}
	if (right < start || left > end) return;
	else if (left <= start && end <= right) {
		seg_tree[node].data = diff * (end - start + 1) + seg_tree[node].data * diff2;
		seg_tree[node].data %= mod;
		if (start != end) {
			seg_tree[node * 2].lazy *= diff2;
			seg_tree[node * 2].lazy += diff;
			seg_tree[node * 2 + 1].lazy *= diff2;
			seg_tree[node * 2 + 1].lazy += diff;
			seg_tree[node * 2].lazy2 *= diff2;
			seg_tree[node * 2 + 1].lazy2 *= diff2;
			seg_tree[node * 2].lazy %= mod;
			seg_tree[node * 2 + 1].lazy %= mod;
			seg_tree[node * 2].lazy2 %= mod;
			seg_tree[node * 2 + 1].lazy2 %= mod;
		}
	}
	else {
		rangeupdate(node * 2, start, (start + end) / 2, left, right, diff, diff2);
		rangeupdate(node * 2 + 1, (start + end) / 2 + 1, end, left, right, diff, diff2);
		seg_tree[node].data = seg_tree[node * 2].data + seg_tree[node * 2 + 1].data;
		seg_tree[node].data %= mod;
	}
}
 
long long sum(int node, int start, int end, int left, int right) {
if (seg_tree[node].lazy != 0 || seg_tree[node].lazy2 != 1) {
		seg_tree[node].data = seg_tree[node].data * seg_tree[node].lazy2 + seg_tree[node].lazy * (end - start + 1);
		seg_tree[node].data %= mod;
		if (start != end) {
			seg_tree[node * 2].lazy = seg_tree[node * 2].lazy * seg_tree[node].lazy2 + seg_tree[node].lazy;
			seg_tree[node * 2 + 1].lazy = seg_tree[node * 2 + 1].lazy * seg_tree[node].lazy2 + seg_tree[node].lazy;
			seg_tree[node * 2].lazy2 *= seg_tree[node].lazy2;
			seg_tree[node * 2 + 1].lazy2 *= seg_tree[node].lazy2;
			seg_tree[node * 2].lazy %= mod;
			seg_tree[node * 2 + 1].lazy %= mod;
			seg_tree[node * 2].lazy2 %= mod;
			seg_tree[node * 2 + 1].lazy2 %= mod;
		}
		seg_tree[node].lazy = 0;
		seg_tree[node].lazy2 = 1;
	}
	if (left > end || right < start) return 0LL;
	if (left <= start && end <= right) return seg_tree[node].data % mod;
	return (sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % mod;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &ary[i]);
	}
	scanf("%d", &m);
	init(1, 1, n);
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b, c;
			long long d;
			scanf("%d %d %lld", &b, &c, &d);
			rangeupdate(1, 1, n, b, c, d, 1LL);
		}
		else if (a == 2) {
			int b, c;
			long long d;
			scanf("%d %d %lld", &b, &c, &d);
			rangeupdate(1, 1, n, b, c, 0LL, d);
		}
		else if (a == 3) {
			int b, c;
			long long d;
			scanf("%d %d %lld", &b, &c, &d);
			rangeupdate(1, 1, n, b, c, d, 0LL);
		}
		else {
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(1, 1, n, b, c) % mod);
		}
	}
	
	return 0;
}
