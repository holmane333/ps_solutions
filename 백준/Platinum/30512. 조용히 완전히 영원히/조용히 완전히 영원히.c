#include <stdio.h>

#define INF 2000000000

typedef struct {
    int val;
    int idx;
} Pair;

Pair tree[400005];
int A[100005];
int final_A[100005];
int last_change[100005];
int freq[100005];
int N, Q;

Pair min_pair(Pair a, Pair b) {
    if (a.val < b.val) return a;
    if (b.val < a.val) return b;
    if (a.idx < b.idx) return a;
    return b;
}

void build(int node, int l, int r) {
    tree[node].val = INF;
    tree[node].idx = INF;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
}

void update(int node, int l, int r, int ql, int qr, int q_val, int q_idx) {
    if (ql <= l && r <= qr) {
        Pair p = {q_val, q_idx};
        tree[node] = min_pair(tree[node], p);
        return;
    }
    int mid = (l + r) / 2;
    if (ql <= mid) update(node * 2, l, mid, ql, qr, q_val, q_idx);
    if (qr > mid) update(node * 2 + 1, mid + 1, r, ql, qr, q_val, q_idx);
}

void dfs(int node, int l, int r, Pair current_min) {
    current_min = min_pair(current_min, tree[node]);
    
    if (l == r) {
        if (current_min.val < A[l]) {
            final_A[l] = current_min.val;
            last_change[l] = current_min.idx;
        } else {
            final_A[l] = A[l];
            last_change[l] = 0;
        }
        return;
    }
    
    int mid = (l + r) / 2;
    dfs(node * 2, l, mid, current_min);
    dfs(node * 2 + 1, mid + 1, r, current_min);
}

int main() {
    if (scanf("%d", &N) != 1) return 0;
    
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    
    build(1, 1, N);

    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++) {
        int L, R, X;
        scanf("%d %d %d", &L, &R, &X);
        update(1, 1, N, L, R, X, i);
    }

    Pair init_pair = {INF, INF};
    dfs(1, 1, N, init_pair);

    for (int i = 1; i <= N; i++) {
        freq[last_change[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        printf("%d%c", final_A[i], i == N ? '\n' : ' ');
    }

    int current_forgotten = freq[0];
    for (int i = 1; i <= Q; i++) {
        current_forgotten += freq[i];
        printf("%d%c", current_forgotten, i == Q ? '\n' : ' ');
    }

    return 0;
}