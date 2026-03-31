#include <stdio.h>

int N, M;
int W[100005], B[100005];
int seg_tree[400005]; 

#define MAX_GIFT 100000

void update(int node, int start, int end, int index, int diff) {
    if (index < start || index > end) return;
    seg_tree[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, diff);
    update(node * 2 + 1, mid + 1, end, index, diff);
}

int find_kth(int node, int start, int end, int k) {
    if (start == end) return start;
    int mid = (start + end) / 2;
    int right_count = seg_tree[node * 2 + 1];
    
    if (k <= right_count) 
        return find_kth(node * 2 + 1, mid + 1, end, k);
    else 
        return find_kth(node * 2, start, mid, k - right_count);
}

int main() {
    if (scanf("%d %d", &N, &M) != 2) return 0;
    
    for (int i = 1; i <= N; i++) {
        int gifts;
        scanf("%d", &gifts);
        update(1, 0, MAX_GIFT, gifts, 1);
    }
    
    for (int i = 1; i <= M; i++) scanf("%d", &W[i]);
    for (int i = 1; i <= M; i++) scanf("%d", &B[i]);

    for (int i = 1; i <= M; i++) {
        int current_gifts = find_kth(1, 0, MAX_GIFT, B[i]);
        
        if (current_gifts < W[i]) {
            printf("0\n");
            return 0;
        }
        
        update(1, 0, MAX_GIFT, current_gifts, -1);
        int remain = current_gifts - W[i];
        update(1, 0, MAX_GIFT, remain, 1);
    }

    printf("1\n");
    return 0;
}