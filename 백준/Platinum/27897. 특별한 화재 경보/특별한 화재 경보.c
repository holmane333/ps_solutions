#include <stdio.h>

long long N, L;
int arr[500005];
long long seg_tree[2000005];

#define MAX_VAL 500000

void update(int node, int start, int end, int index, int diff) {
    if (index < start || index > end) return;
    seg_tree[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, diff);
    update(node * 2 + 1, mid + 1, end, index, diff);
}

long long query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return seg_tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
    if (scanf("%lld %lld", &N, &L) != 2) return 0;

    long long val = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        val += query(1, 1, N, arr[i] + 1, N);
        update(1, 1, N, arr[i], 1);
    }

    long long mv = N * (N - 1) / 2;
    long long res = val + L;

    if (res > mv) {
        res = mv;
    }

    printf("%lld\n", res);

    return 0;
}