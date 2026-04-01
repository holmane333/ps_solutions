#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    ll val;
    int origin_idx;
} Element;

int N;
ll A[300005];
int compressed_idx[300005];
ll tree[1200005];

int compare(const void* a, const void* b) {
    ll v1 = ((Element*)a)->val;
    ll v2 = ((Element*)b)->val;
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

void update(int node, int start, int end, int idx, ll val) {
    if (idx < start || idx > end) return;
    if (start == end) {
        if (val > tree[node]) tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    tree[node] = (tree[node * 2] > tree[node * 2 + 1]) ? tree[node * 2] : tree[node * 2 + 1];
}

ll query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    ll l_max = query(node * 2, start, mid, left, right);
    ll r_max = query(node * 2 + 1, mid + 1, end, left, right);
    return (l_max > r_max) ? l_max : r_max;
}

Element sorted[300005];

int main() {
    if (scanf("%d", &N) != 1) return 0;
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
        sorted[i].val = A[i];
        sorted[i].origin_idx = i;
    }

    qsort(sorted + 1, N, sizeof(Element), compare);
    int rank = 1;
    for (int i = 1; i <= N; i++) {
        if (i > 1 && sorted[i].val > sorted[i - 1].val) rank++;
        compressed_idx[sorted[i].origin_idx] = rank;
    }

    ll total_max = 0;
    for (int i = 1; i <= N; i++) {
        int cur_rank = compressed_idx[i];
        ll prev_max_sum = query(1, 1, rank, 1, cur_rank - 1);
        ll current_sum = prev_max_sum + A[i];
        
        update(1, 1, rank, cur_rank, current_sum);
        
        if (current_sum > total_max) total_max = current_sum;
    }

    printf("%lld\n", total_max);

    return 0;
}