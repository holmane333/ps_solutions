#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

struct Block {
    int w, h;
};

bool compare(const Block& a, const Block& b) {
    if (a.w != b.w) return a.w > b.w;
    return a.h < b.h;
}

int n;
Block blocks[MAXN];
int h_coords[MAXN], h_cnt;
long long seg_tree[MAXN * 4];

void update(int node, int start, int end, int idx, long long val) {
    if (idx < start || idx > end) return;
    if (start == end) {
        seg_tree[node] = max(seg_tree[node], val);
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    seg_tree[node] = max(seg_tree[node * 2], seg_tree[node * 2 + 1]);
}

long long query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return seg_tree[node];
    int mid = (start + end) / 2;
    return max(query(node * 2, start, mid, left, right),
               query(node * 2 + 1, mid + 1, end, left, right));
}

struct TempUpdate {
    int h_idx;
    long long new_val;
} temp_updates[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> blocks[i].w >> blocks[i].h;
        h_coords[i] = blocks[i].h;
    }

    sort(h_coords, h_coords + n);
    h_cnt = unique(h_coords, h_coords + n) - h_coords;

    sort(blocks, blocks + n, compare);

    for (int i = 0; i < n; ) {
        int j = i;
        int temp_cnt = 0;

        while (j < n && blocks[j].w == blocks[i].w) {
            int h_idx = lower_bound(h_coords, h_coords + h_cnt, blocks[j].h) - h_coords + 1;
            long long max_prev = query(1, 1, h_cnt, 1, h_idx);
            temp_updates[temp_cnt++] = {h_idx, max_prev + blocks[j].h};
            j++;
        }

        for (int k = 0; k < temp_cnt; k++) {
            update(1, 1, h_cnt, temp_updates[k].h_idx, temp_updates[k].new_val);
        }
        i = j;
    }
    
    cout << seg_tree[1];

    return 0;
}