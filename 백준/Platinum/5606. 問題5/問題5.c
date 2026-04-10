#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
#pragma warning(disable:4996)

typedef struct line {
	int pos, p1, p2, val;
}line;

int n, r;
line ary[20010];
line bry[20010];

int seg_cnt[40040];
int seg_len[40040];
int seg_inter[40040];
int seg_l[40040];
int seg_r[40040];

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
	} else {
		int mid = (start + end) / 2;
		update(node * 2, start, mid, left, right, val);
		update(node * 2 + 1, mid + 1, end, left, right, val);
	}

	if (seg_cnt[node] > 0) {
		seg_len[node] = end - start + 1;
		seg_inter[node] = 1;
		seg_l[node] = 1;
		seg_r[node] = 1;
	} else {
		if (start == end) {
			seg_len[node] = 0;
			seg_inter[node] = 0;
			seg_l[node] = 0;
			seg_r[node] = 0;
		} else {
			seg_len[node] = seg_len[node * 2] + seg_len[node * 2 + 1];
			seg_inter[node] = seg_inter[node * 2] + seg_inter[node * 2 + 1];
			if (seg_r[node * 2] == 1 && seg_l[node * 2 + 1] == 1) {
				seg_inter[node]--;
			}
			seg_l[node] = seg_l[node * 2];
			seg_r[node] = seg_r[node * 2 + 1];
		}
	}
}

int main(void) {
	scanf("%d %d", &n, &r);
	
	int idx1 = 0;
	int idx2 = 0;

	for (int i = 1; i <= n; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		
		++idx1;
		ary[idx1].pos = x1; ary[idx1].p1 = y1; ary[idx1].p2 = y2 - 1; ary[idx1].val = 1;
		++idx1;
		ary[idx1].pos = x2; ary[idx1].p1 = y1; ary[idx1].p2 = y2 - 1; ary[idx1].val = -1;

		++idx2;
		bry[idx2].pos = y1; bry[idx2].p1 = x1; bry[idx2].p2 = x2 - 1; bry[idx2].val = 1;
		++idx2;
		bry[idx2].pos = y2; bry[idx2].p1 = x1; bry[idx2].p2 = x2 - 1; bry[idx2].val = -1;
	}
	// assert(!(ary[1].pos == 0 && ary[2].pos == 3 && bry[1].pos == 0 && bry[2].pos == 2));

	qsort(ary + 1, idx1, sizeof(line), compare1);
	qsort(bry + 1, idx2, sizeof(line), compare1);

	long long res_area = 0LL;
	long long res_peri = 0LL;

	for (int i = 1, prev = ary[1].pos; i <= idx1; ++i) {
		int dist = ary[i].pos - prev;
		res_area += 1LL * seg_len[1] * dist;
		res_peri += 2LL * seg_inter[1] * dist;

		update(1, 0, 10000, ary[i].p1, ary[i].p2, ary[i].val);
		prev = ary[i].pos;
	}

	if (r == 1) {
		printf("%lld\n", res_area);
		return 0;
	}

	memset(seg_cnt, 0, sizeof(seg_cnt));
	memset(seg_len, 0, sizeof(seg_len));
	memset(seg_inter, 0, sizeof(seg_inter));
	memset(seg_l, 0, sizeof(seg_l));
	memset(seg_r, 0, sizeof(seg_r));

	for (int i = 1, prev = bry[1].pos; i <= idx2; ++i) {
		int dist = bry[i].pos - prev;
		res_peri += 2LL * seg_inter[1] * dist;

		update(1, 0, 10000, bry[i].p1, bry[i].p2, bry[i].val);
		prev = bry[i].pos;
	}

	printf("%lld\n", res_area);
	printf("%lld\n", res_peri);

	return 0;
}