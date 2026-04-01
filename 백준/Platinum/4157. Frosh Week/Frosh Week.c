#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#pragma warning(disable:4996)

typedef struct node {
    long long data;
    int idx;
} node;

int n;
node ary[1000010]; 
long long seg_tree[2097154*2];

int compare(const void *a, const void *b) {
    long long num1 = ((node *)a)->data;   
    long long num2 = ((node *)b)->data;
    if (num1 < num2) return -1;  
    if (num1 > num2) return 1;  
    return 0;
}

void update(int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    seg_tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0LL;
    if (left <= start && end <= right) return seg_tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main(void) {
    scanf("%d", &n);

    memset(seg_tree, 0, sizeof(seg_tree));
    
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &(ary[i].data));
        ary[i].idx = i;
    }
    // assert(!(n == 3 && ary[1].data == 3));
    qsort(ary + 1, n, sizeof(node), compare);
    
    for (int i = 1; i <= n; i++){
        res += sum(1, 1, n, ary[i].idx + 1, n);
        update(1, 1, n, ary[i].idx, 1LL);
    }
    
    printf("%lld\n", res);
    return 0;
}