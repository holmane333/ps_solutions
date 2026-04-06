#include <stdio.h>
#include <stdbool.h>

int B[100005];
int A[200005];
int tree[800005];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = 1;
        return;
    }
    int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int start, int end, int idx) {
    if (idx < start || idx > end) return;
    if (start == end) {
        tree[node] = 0;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx);
    update(node * 2 + 1, mid + 1, end, idx);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query_min(int node, int start, int end) {
    if (start == end) return start;
    int mid = (start + end) / 2;
    if (tree[node * 2] > 0) return query_min(node * 2, start, mid);
    return query_min(node * 2 + 1, mid + 1, end);
}

int query_max(int node, int start, int end) {
    if (start == end) return start;
    int mid = (start + end) / 2;
    if (tree[node * 2 + 1] > 0) return query_max(node * 2 + 1, mid + 1, end);
    return query_max(node * 2, start, mid);
}

bool is_available(int node, int start, int end, int idx) {
    if (start == end) return tree[node] == 1;
    int mid = (start + end) / 2;
    if (idx <= mid) return is_available(node * 2, start, mid, idx);
    return is_available(node * 2 + 1, mid + 1, end, idx);
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }

    int MAX_VAL = 2 * N - 1;
    build(1, 1, MAX_VAL);

    A[0] = B[0];
    update(1, 1, MAX_VAL, B[0]);
    int idx = 1;

    for (int i = 1; i < N; i++) {
        if (B[i] == B[i-1]) {
            int cur_min = query_min(1, 1, MAX_VAL);
            A[idx++] = cur_min;
            update(1, 1, MAX_VAL, cur_min);

            int cur_max = query_max(1, 1, MAX_VAL);
            A[idx++] = cur_max;
            update(1, 1, MAX_VAL, cur_max);

        } else if (B[i] > B[i-1]) {
            if (is_available(1, 1, MAX_VAL, B[i])) {
                A[idx++] = B[i];
                update(1, 1, MAX_VAL, B[i]);
            } else {
                int cur_max = query_max(1, 1, MAX_VAL);
                A[idx++] = cur_max;
                update(1, 1, MAX_VAL, cur_max);
            }
            int cur_max = query_max(1, 1, MAX_VAL);
            A[idx++] = cur_max;
            update(1, 1, MAX_VAL, cur_max);

        } else {
            if (is_available(1, 1, MAX_VAL, B[i])) {
                A[idx++] = B[i];
                update(1, 1, MAX_VAL, B[i]);
            } else {
                int cur_min = query_min(1, 1, MAX_VAL);
                A[idx++] = cur_min;
                update(1, 1, MAX_VAL, cur_min);
            }
            int cur_min = query_min(1, 1, MAX_VAL);
            A[idx++] = cur_min;
            update(1, 1, MAX_VAL, cur_min);
        }
    }

    for (int i = 0; i < 2 * N - 1; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}