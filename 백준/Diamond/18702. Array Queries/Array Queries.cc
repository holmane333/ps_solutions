#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

static const int buf_size = 1 << 18;

inline int getChar() {
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if (pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
    if (pos == len) return -1;
    return buf[pos++];
}

inline int readChar() {
    int c = getChar();
    while (c >= 0 && c <= 32) c = getChar();
    return c;
}

template <class T = int>
inline T readInt() {
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-') s = -1, c = getChar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
}

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar(int x) {
    if (write_pos == buf_size) fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}

template <class T>
inline void writeInt(T x, char end = 0) {
    if (x < 0) writeChar('-'), x = -x;
    char s[24]; int n = 0;
    while (x || !n) s[n++] = '0' + x % 10, x /= 10;
    while (n--) writeChar(s[n]);
    if (end) writeChar(end);
}

struct Flusher {
    ~Flusher() { if (write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0; }
} flusher;

long long max_val[400005], min_val[400005], tree_sum[400005], lazy[400005], arr[100005];

inline void apply(int node, int start, int end, long long val) {
    max_val[node] += val;
    min_val[node] += val;
    tree_sum[node] += (long long)(end - start + 1) * val;
    lazy[node] += val;
}

inline void push_down(int node, int start, int end) {
    if (lazy[node] != 0) {
        int mid = (start + end) >> 1;
        apply(node << 1, start, mid, lazy[node]);
        apply(node << 1 | 1, mid + 1, end, lazy[node]);
        lazy[node] = 0;
    }
}

inline void pull(int node) {
    int l = node << 1, r = l | 1;
    max_val[node] = max(max_val[l], max_val[r]);
    min_val[node] = min(min_val[l], min_val[r]);
    tree_sum[node] = tree_sum[l] + tree_sum[r];
}

void build(int node, int start, int end) {
    lazy[node] = 0;
    if (start == end) {
        max_val[node] = min_val[node] = tree_sum[node] = arr[start];
        return;
    }
    int mid = (start + end) >> 1;
    build(node << 1, start, mid);
    build(node << 1 | 1, mid + 1, end);
    pull(node);
}

void update_add(int node, int start, int end, int l, int r, long long val) {
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        apply(node, start, end, val);
        return;
    }
    push_down(node, start, end);
    int mid = (start + end) >> 1;
    update_add(node << 1, start, mid, l, r, val);
    update_add(node << 1 | 1, mid + 1, end, l, r, val);
    pull(node);
}

void update_sqrt(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        if (max_val[node] <= 1) return;
        if (max_val[node] - min_val[node] <= 1) {
            long long v1 = (long long)sqrt(max_val[node]) - max_val[node];
            long long v2 = (long long)sqrt(min_val[node]) - min_val[node];
            if (v1 == v2) {
                apply(node, start, end, v1);
                return;
            }
        }
    }
    push_down(node, start, end);
    int mid = (start + end) >> 1;
    update_sqrt(node << 1, start, mid, l, r);
    update_sqrt(node << 1 | 1, mid + 1, end, l, r);
    pull(node);
}

long long query_sum(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree_sum[node];
    push_down(node, start, end);
    int mid = (start + end) >> 1;
    return query_sum(node << 1, start, mid, l, r) + query_sum(node << 1 | 1, mid + 1, end, l, r);
}

void solve() {
    int n = readInt(), q = readInt();
    for (int i = 1; i <= n; i++) arr[i] = readInt();
    build(1, 1, n);
    while (q--) {
        int op = readInt();
        int l = readInt();
        int r = readInt();
        if (op == 1) update_sqrt(1, 1, n, l, r);
        else if (op == 3) update_add(1, 1, n, l, r, readInt<long long>());
        else writeInt(query_sum(1, 1, n, l, r), '\n');
    }
}

int main() {
    int t = readInt();
    while (t--) {
        solve();
    }
    return 0;
}