#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#pragma warning(disable:4996)

typedef struct line {
	int pos, p1, p2, val, id;
} line;

int n;
line ary[100010];
int valid[50010];

int seg_cnt[4000040];

int compare1(const void* num1, const void* num2) {
	line a = *(line*)num1;
	line b = *(line*)num2;
	if (a.pos == b.pos) return b.val - a.val;
	return a.pos - b.pos;
}

void update(int node, int start, int end, int left, int right, int val) {
	if (right < start || left > end) return;
	
	if (left <= start && end <= right) {
		seg_cnt[node] += val;
		return;
	}
	
	int mid = (start + end) / 2;
	update(node * 2, start, mid, left, right, val);
	update(node * 2 + 1, mid + 1, end, left, right, val);
}

int query(int node, int start, int end, int idx) {
	if (idx < start || idx > end) return 0;
	if (start == end) return seg_cnt[node];
	
	int mid = (start + end) / 2;
	return seg_cnt[node] + query(node * 2, start, mid, idx) + query(node * 2 + 1, mid + 1, end, idx);
}

int main(void) {
	scanf("%d", &n);
	
	int idx1 = 0;

	for (int i = 1; i <= n; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		// assert(!(x1 == 2 && y1 == 0 && x2 == 8 && y2 == 9));
		
		++idx1;
		ary[idx1].pos = x1; ary[idx1].p1 = y1; ary[idx1].p2 = y2; ary[idx1].val = 1; ary[idx1].id = i;
		++idx1;
		ary[idx1].pos = x2; ary[idx1].p1 = y1; ary[idx1].p2 = y2; ary[idx1].val = -1; ary[idx1].id = i;
	}

	qsort(ary + 1, idx1, sizeof(line), compare1);

	int ans = 0;

	for (int i = 1; i <= idx1; ++i) {
		int id = ary[i].id;
		
		if (ary[i].val == 1) {
			if (query(1, 0, 1000000, ary[i].p1) == 0) {
				valid[id] = 1;
				ans++;
				update(1, 0, 1000000, ary[i].p1, ary[i].p2, 1);
			}
		} else {
			if (valid[id] == 1) {
				update(1, 0, 1000000, ary[i].p1, ary[i].p2, -1);
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}