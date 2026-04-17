#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int n;
int a[MAXN], b[MAXN];
int tree_max[MAXN * 4];
int tree_min[MAXN * 4];

void init(int node, int start, int end) {
    if (start == end) {
        tree_max[node] = a[start];
        tree_min[node] = b[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree_max[node] = max(tree_max[node * 2], tree_max[node * 2 + 1]);
    tree_min[node] = min(tree_min[node * 2], tree_min[node * 2 + 1]);
}

int query_max(int node, int start, int end, int left, int right) {
    if (left > right || left > end || right < start) return -1;
    if (left <= start && end <= right) return tree_max[node];
    int mid = (start + end) / 2;
    return max(query_max(node * 2, start, mid, left, right), query_max(node * 2 + 1, mid + 1, end, left, right));
}

int query_min(int node, int start, int end, int left, int right) {
    if (left > right || left > end || right < start) return 1e9;
    if (left <= start && end <= right) return tree_min[node];
    int mid = (start + end) / 2;
    return min(query_min(node * 2, start, mid, left, right), query_min(node * 2 + 1, mid + 1, end, left, right));
}

bool check(int k) {
    for (int i = 1; i <= n - k + 1; i++) {
        int max_a = query_max(1, 1, n, i, i + k - 1);
        int min_b = query_min(1, 1, n, i, i + k - 1);
        if (min_b - max_a + 1 >= k) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    init(1, 1, n);

    int left = 1, right = n;
    int ans = 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}