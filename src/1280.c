#include <stdio.h>
#pragma warning(disable:4996)
#define mod 1000000007
#define max 200010
 
typedef struct pair {
	long long cnt;
	long long data;
} pair;
 
int n, m, k;
long long ary[1000002];
pair seg_tree[2097154];
 
void update(int node, int start, int end, int index, long long diff) {
	if (index < start || index > end) return;
	if (start == end) {
		seg_tree[node].cnt += 1LL;
		seg_tree[node].data += diff;
		return;
	}
	update(node * 2, start, (start + end) / 2, index, diff);
	update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	seg_tree[node].cnt = seg_tree[node * 2].cnt + seg_tree[node * 2 + 1].cnt;
	seg_tree[node].data = seg_tree[node * 2].data + seg_tree[node * 2 + 1].data;
}
 
pair sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		pair new1;
		new1.cnt = 0LL;
		new1.data = 0LL;
		return new1;
	}
	if (left <= start && end <= right) return seg_tree[node];
	pair a = sum(node * 2, start, (start + end) / 2, left, right);
	pair b = sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	pair new1;
	new1.cnt = a.cnt + b.cnt;
	new1.data = a.data + b.data;
	return new1;
}
 
int main(void) {
	scanf("%d", &n);
	int data;
	long long res = 1;
	scanf("%d", &data);
	data++;
	update(1, 1, max, data, (long long)data);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &data);
		data++;
		pair left = sum(1, 1, max, 1, data - 1 > 0 ? data - 1 : 1);
		pair right = sum(1, 1, max, data + 1 < max ? data + 1 : max, max);
		//printf("%lld %lld %lld %lld\n", 1, data - 1 > 0 ? data - 1 : 1, data + 1 < max ? data + 1 : max, max);
		long long distance = ((long long)data * left.cnt - left.data + right.data - (long long)data * right.cnt) % mod;
		res = (res * distance) % mod;
		//printf("%d %lld %lld %lld %lld %lld %lld\n", data, left.cnt, left.data, right.cnt, right.data, res, distance);
		update(1, 1, max, data, (long long)data);
	}
	
	printf("%lld\n", res);
	return 0;
}