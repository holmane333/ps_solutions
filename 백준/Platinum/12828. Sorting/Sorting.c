#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long A, B;
long long seg_tree[400005];

#define MOD 1000000007

struct Item {
    char str[25];
    int num_idx;
} items[100005];

int lex_rank[100005];

int cmp(const void* a, const void* b) {
    return strcmp(((struct Item*)a)->str, ((struct Item*)b)->str);
}

void update(int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    seg_tree[node] = (seg_tree[node] + diff) % MOD;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, diff);
    update(node * 2 + 1, mid + 1, end, index, diff);
}

long long query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return seg_tree[node];
    int mid = (start + end) / 2;
    return (query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r)) % MOD;
}

int main() {
    if (scanf("%lld %lld", &A, &B) != 2) return 0;

    int N = B - A + 1;

    for (int i = 1; i <= N; i++) {
        sprintf(items[i].str, "%lld", A + i - 1);
        items[i].num_idx = i;
    }

    qsort(items + 1, N, sizeof(struct Item), cmp);

    for (int i = 1; i <= N; i++) {
        lex_rank[items[i].num_idx] = i;
    }

    long long res = 1; 

    for (int i = 1; i <= N; i++) {
        int rank = lex_rank[i];
        long long val = query(1, 1, N, 1, rank - 1);
        long long dp_val = (val + 1) % MOD; 
        res = (res + dp_val) % MOD;
        update(1, 1, N, rank, dp_val);
    }

    printf("%lld\n", res);

    return 0;
}